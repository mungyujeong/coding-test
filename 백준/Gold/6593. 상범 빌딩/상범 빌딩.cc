#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 30

using namespace std;

int l, r, c, curr_x, curr_y, curr_z, ex, ey, ez;
int board[MAX_N][MAX_N][MAX_N];
queue<tuple<int, int, int>> Q;
int dz[] = {1, -1, 0, 0, 0, 0};
int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 0, 1, -1};

void bfs() {
    while (!Q.empty()) {
        int z, x, y;
        tie(z, x, y) = Q.front(); Q.pop();
        for (int d = 0; d < 6; d++) {
            int nz = z + dz[d];
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nz < 0 || nx < 0 || ny < 0 || nz >= l || nx >= r || ny >= c) continue;
            if (board[nz][nx][ny] == -1) continue;
            if (board[nz][nx][ny] > 0) continue;
            Q.push({nz, nx, ny});
            board[nz][nx][ny] = board[z][x][y] + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0)
            break;
        
        int answer = 0;
        for (int i = 0; i < l; i++) 
            for (int j = 0;j < r; j++) 
                fill(board[i][j], board[i][j] + c, 0);

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    char tmp;
                    cin >> tmp;
                    if (tmp == '#') {
                        board[i][j][k] = -1;
                    } else {
                        board[i][j][k] = 0;
                        if (tmp == 'S') {
                            curr_z = i;
                            curr_x = j;
                            curr_y = k;
                            Q.push({i, j, k});
                            board[i][j][k] = 1;
                        }
                        if (tmp == 'E') {
                            ez = i;
                            ex = j;
                            ey = k;
                        }
                    }
                }
            }
        }

        bfs();
        int cnt = board[ez][ex][ey];
        if (cnt) cout << "Escaped in " << cnt - 1 << " minute(s).\n";
        else cout << "Trapped!\n";
    }
}