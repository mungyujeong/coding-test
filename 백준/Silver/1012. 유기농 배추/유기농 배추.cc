#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 50

using namespace std;

int t, m, n, k;
queue<pair<int, int>> Q;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int grid[][MAX_N], int sx, int sy) {
    Q.push({sx, sy});
    while(!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (grid[nx][ny] > 1 || grid[nx][ny] == 0) continue;
            grid[nx][ny] = grid[x][y] + 1;
            Q.push({nx, ny});
        }
    }
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> m >> n >> k;
        int grid[MAX_N][MAX_N] = {};

        for (int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;
            grid[y][x] = 1;
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    bfs(grid, i, j);
                    cnt++;
                }
            }
        }
        // cout << endl;
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << grid[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        cout << cnt << '\n';
    }
}