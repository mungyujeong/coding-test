#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 600

using namespace std;

int n, m;
char board[MAX_N][MAX_N];
queue<pair<int, int>> Q;
bool visited[MAX_N][MAX_N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'I') {
                Q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    int answer = 0;
    while (!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!in_range(nx, ny)) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] == 'X') continue;
            if (board[nx][ny] == 'P') {
                answer++;
                board[nx][ny] = 'O';
            }
            Q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }

    if (answer == 0) cout << "TT";
    else cout << answer;
}