#include <iostream>
#include <queue>
#include <climits>
#include <tuple>

#define MAX_N 100

using namespace std;

int n;
int answer = INT_MAX;
int board[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int mapping[MAX_N][MAX_N];
queue<pair<int, int>> Q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void land(int sx, int sy, int cnt) {
    int x, y;
    Q.push({sx, sy});
    visited[sx][sy] = 1;
    mapping[sx][sy] = cnt;

    while (!Q.empty()) {
        tie(x, y) = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] == 0) continue;
            Q.push({nx, ny});
            mapping[nx][ny] = cnt;
            visited[nx][ny] = 1;
        }
    }
}

void bridge(int sx, int sy) {
    int length[MAX_N][MAX_N] = {};
    int group = mapping[sx][sy];
    int x, y;
    Q.push({sx, sy});
    
    while (!Q.empty()) {
        tie(x, y) = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (mapping[nx][ny] == group) continue;
            if (length[nx][ny] > 0) continue;
            if (mapping[nx][ny] == 0) {
                Q.push({nx, ny});
                length[nx][ny] = length[x][y] + 1;
            }
            if (mapping[nx][ny] != 0 && mapping[nx][ny] != group) {
                answer = min(answer, length[x][y]);
                while (!Q.empty())
                    Q.pop();
                break;
            }
        }
    }
    // cout << "==============\n";
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) 
    //         cout << length[i][j] << ' ';
    //     cout << endl;
    // }
    // cout << "=====answer=====" << answer <<'\n';
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] && !visited[i][j]) {
                land(i, j, cnt);
                cnt++;
            }
        }
    }

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            if (mapping[i][j] > 0) 
                bridge(i, j);
    
    cout << answer;
}