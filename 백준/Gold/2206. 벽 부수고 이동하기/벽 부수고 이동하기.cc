#include <iostream>
#include <queue>
#include <tuple>
#include <climits>

#define MAX_N 1000

using namespace std;

int n, m;
int board[MAX_N + 1][MAX_N + 1][2];
queue<tuple<int, int, int>> Q;
int answer = INT_MAX;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int x, y, broken;
char c;

void bfs() {
    while (!Q.empty()) {
        tie(x, y, broken) = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny][0] == 1) {
                if (!broken) {
                    board[nx][ny][1] = board[x][y][0] + 1;
                    Q.push({nx, ny, 1});
                }
            }
            else if (board[nx][ny][0] == 0) {
                if (broken == 1 && board[nx][ny][1]) continue;
                board[nx][ny][broken] = board[x][y][broken] + 1;
                Q.push({nx, ny, broken});
            }
        }
    }

    if (board[n - 1][m - 1][0] != 0)
        answer = min(answer, board[n - 1][m - 1][0]);
    if (board[n - 1][m - 1][1] != 0)
        answer = min(answer, board[n - 1][m - 1][1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            board[i][j][0] = c - '0';
        }
    }

    Q.push({0, 0, 0});
    board[0][0][0]++;
    bfs();

    // if (n == 1 && m == 1) cout << 0;
    if (answer == INT_MAX) cout << -1;
    else cout << answer;
}