#include <iostream>
#include <tuple>
#include <queue>

#define MAX_N 100

using namespace std;

int board[MAX_N + 1][MAX_N + 1][MAX_N + 1];
int visited[MAX_N + 1][MAX_N + 1][MAX_N + 1];
int m, n, h;
queue<tuple<int, int, int>> Q;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void bfs() {
    while (!Q.empty()) {
        int x, y, z;
        tie(x, y, z) = Q.front(); Q.pop();
        for (int d = 0; d < 6; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            int nz = z + dz[d];
            if (nx < 0 || ny < 0 || nz < 0 || x >= h || y >= n || z >= m) continue;
            if (visited[nx][ny][nz]) continue;
            if (board[nx][ny][nz] == -1 || board[nx][ny][nz] >= 1) continue;
            Q.push({nx, ny, nz});
            visited[nx][ny][nz] = 1;
            board[nx][ny][nz] = board[x][y][z] + 1;
        }
    }
}

int main() {
    cin >> m >> n >> h;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int t = 0; t < m; t++) {
                cin >> board[i][j][t];
                if (board[i][j][t] == 1) {
                    Q.push({i, j, t});
                    visited[i][j][t] = 1;
                }
            }
        }
    }

    int cnt = 0;
    bfs();

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int t = 0; t < m; t++) {
                if (board[i][j][t] == 0) {
                    cout << -1;
                    return 0;
                } else if (board[i][j][t] == -1) continue;
                cnt = max(cnt, board[i][j][t]);
            }
        }
    }

    cout << cnt - 1;
}
