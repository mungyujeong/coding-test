#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 1'000
#define MAX_K 10
#define DAY 0
#define NIGHT 1

using namespace std;

int n, m, k, answer = -1;
char board[MAX_N][MAX_N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int Simulate() {
    // x, y, 부순 횟수, 낮밤, 이동거리
    queue<tuple<int, int, int, int, int>> Q;
    // x, y, 부순 횟수, 낮밤
    bool visited[MAX_N][MAX_N][MAX_K + 1][2] = {};

    Q.push({0, 0, 0, DAY, 1});
    visited[0][0][0][DAY] = true;

    while (!Q.empty()) {
        int x, y, h, dn, dist;
        tie(x, y, h, dn, dist) = Q.front(); Q.pop();
        int nxt = (dn == DAY) ? NIGHT : DAY;

        if (x == n - 1 && y == m - 1) {
            answer = dist;
            break;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!InRange(nx, ny)) continue;
            if (visited[nx][ny][h][nxt]) continue;
            if (board[nx][ny] == '1') {
                if (k == h) continue;
                if (dn == NIGHT) {
                    if (visited[x][y][h][nxt]) continue;

                    visited[x][y][h][nxt] = true;
                    Q.push({x, y, h, nxt, dist + 1});
                    continue;
                }
                else {
                    if (visited[nx][ny][h + 1][nxt]) continue;

                    visited[nx][ny][h + 1][nxt] = true;
                    Q.push({nx, ny, h + 1, nxt, dist + 1});
                    continue;
                }
            }
            else {
                visited[nx][ny][h][nxt] = true;
                Q.push({nx, ny, h, nxt, dist + 1});
            }
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    cout << Simulate();
}