#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 1'000

using namespace std;

int n, m, board[MAX_N][MAX_N], grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
queue<pair<int, int>> Q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void bfs() {
    int x, y;
    while (!Q.empty()) {
        tie(x, y) = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!in_range(nx, ny)) continue;
            if (board[nx][ny] == 0) continue;
            if (visited[nx][ny]) continue;
            grid[nx][ny] = grid[x][y] + 1;
            visited[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    // -1 로 초기화
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            grid[i][j] = -1;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                Q.push({i, j});
                visited[i][j] = true;
                grid[i][j] = 0;
            }
            else if (board[i][j] == 0)
                grid[i][j] = 0;
        }

    bfs();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            cout << grid[i][j] << ' ';
        cout << endl;
    }
}