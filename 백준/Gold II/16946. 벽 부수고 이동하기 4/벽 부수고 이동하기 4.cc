#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

#define MAX_N 1'000

using namespace std;

int n, m, grid[MAX_N][MAX_N], tmp[MAX_N][MAX_N];
char board[MAX_N][MAX_N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void bfs(int x, int y) {
    queue<pair<int, int>> Q;
    vector<pair<int, int>> v;

    int cnt = 1;
    Q.push({x, y});
    grid[x][y] = 1;

    while (!Q.empty()) {
        tie(x, y) = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!in_range(nx, ny)) continue;
            if (grid[nx][ny]) continue;
            if (board[nx][ny] == '1') {
                v.push_back({nx, ny});
                grid[nx][ny] = 1;
                continue;
            }
            Q.push({nx, ny});
            cnt++;
            grid[nx][ny] = 1;
        }
    }

    for (auto i : v) {
        tie(x, y) = i;
        grid[x][y] = 0;
        tmp[x][y] += cnt;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '1' || grid[i][j]) continue;
            bfs(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '1') cout << (tmp[i][j] + 1) % 10;
            else cout << tmp[i][j];
        }
        cout << '\n';
    }
}