#include <iostream>
#include <queue>
#include <tuple>

#define MAX_R 1000

using namespace std;

int r, c;
int board[MAX_R][MAX_R];
queue<pair<int, int>> start;
queue<pair<int, int>> Q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs() {
    while (!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if (board[nx][ny] == -2 || board[nx][ny] >= 0) continue;
            Q.push({nx, ny});
            board[nx][ny] = board[x][y] + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    for (int i = 0 ; i < r; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < c; j++) {
            if (str[j] == '#') {
                board[i][j] = -2;
            } else if (str[j] == 'F') {
                Q.push({i, j});
            } else if (str[j] == 'J') {
                start.push({i, j});
            } else {
                // .
                board[i][j] = -1;
            }
        }
    }

    bfs();

    // for (int i = 0; i < r; i++){
    //     for (int j = 0; j < c;j++){
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    int visited[MAX_R][MAX_R];
    while (!start.empty()) {
        int x, y;
        tie(x, y) = start.front(); start.pop();
        visited[x][y] = 1;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
                cout << board[x][y] + 1;
                return 0;
            }
            if (board[nx][ny] == -2 || visited[nx][ny]) continue;
            if (board[nx][ny] > board[x][y] + 1 || board[nx][ny] == -1) {
                
                start.push({nx, ny});
                board[nx][ny] = board[x][y] + 1;
                visited[nx][ny] = 1;
            }
        }
    }

    cout << "IMPOSSIBLE";
}