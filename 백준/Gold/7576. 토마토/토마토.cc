#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
#include <climits>

#define MAX_N 1000

using namespace std;

int n, m, answer = INT_MIN;
int board[MAX_N][MAX_N];
vector<pair<int, int>> v;
queue<pair<int, int>> Q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs() {
    while (!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front();
        Q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] == -1) continue;
            if (board[nx][ny] > board[x][y] + 1 || board[nx][ny] == 0) {
                Q.push({nx, ny});
                board[nx][ny] = board[x][y] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                Q.push({i, j});
            }
        }
    }

    bfs();

    int answer = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == -1) continue;
            if (board[i][j] == 0) {
                cout << -1;
                return 0;
            }
            answer = max(answer, board[i][j]);
        }
    }

    cout << answer - 1;
}