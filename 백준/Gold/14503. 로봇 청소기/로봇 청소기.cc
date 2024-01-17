#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 50

using namespace std;

int n, m, x, y, d, answer;
// 북 동 남 서
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int board[MAX_N][MAX_N];
int clean[MAX_N][MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin >> x >> y >> d;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    
    queue<pair<int, int>> Q;
    Q.push({x, y});

    while (!Q.empty()) {
        tie(x, y) = Q.front(); Q.pop();
        if (clean[x][y] == 0) {
            clean[x][y] = 1;
            answer++;
        }
        int cnt = 0;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (board[nx][ny] == 1 || clean[nx][ny] == 1) {
                cnt++;
                continue;
            }
        }

        if (cnt == 4) {
            int nx = x - dx[d];
            int ny = y - dy[d];
            if (board[nx][ny] == 1) 
                break;
            else {
                Q.push({nx, ny});
                continue;
            }
        }
        else {
            d = (d + 3) % 4;
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (board[nx][ny] == 0 && clean[nx][ny] == 0) {
                Q.push({nx, ny});
            }
            else Q.push({x, y});
        }
    }   
    cout << answer;
}