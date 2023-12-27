#include <iostream>
#include <queue>
#include <tuple>
#include <climits>
#include <vector>
#include <algorithm>

#define MAX_N 500

using namespace std;

int n, m;
int grid[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
queue<pair<int, int>> Q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(int x, int y) {
    int cnt = 0;
    Q.push({x, y});
    visited[x][y] = 1;
    while (!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front();
        Q.pop();
        cnt++;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny]) continue;
            if (grid[nx][ny] == 0) continue;
            Q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            grid[i][j] = x;
        }
    }

    int cnt = 0;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                answer = max(answer, bfs(i, j));
                cnt++;
            }
        }
    }

    cout << cnt << '\n' << answer;
}