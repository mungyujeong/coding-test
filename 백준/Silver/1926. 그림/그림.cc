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
int mapping[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
queue<pair<int, int>> Q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y, int cnt) {
    // cout << x << " " << y << '\n';
    Q.push({x, y});
    visited[x][y] = 1;
    mapping[x][y] = cnt;
    while (!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front();
        Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny]) continue;
            if (grid[nx][ny] == 0) continue;
            Q.push({nx, ny});
            visited[nx][ny] = 1;
            mapping[nx][ny] = cnt;
        }
    }
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

    int cnt = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                bfs(i, j, cnt);
                cnt++;
            }
        }
    }

    vector<int> answer(cnt + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mapping[i][j]) {
                answer[mapping[i][j]]++;
            }
        }
    }
    cout << cnt - 1 << '\n' << *max_element(answer.begin(), answer.end());
}