#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>

#define MAX_N 100

using namespace std;

int m, n, k;
int board[MAX_N][MAX_N];
vector<int> v;
queue<pair<int, int>> Q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(int sx, int sy) {
    int cnt = 0;
    board[sx][sy] = 1;
    Q.push({sx, sy});
    while (!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front(); Q.pop();
        cnt++;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (board[nx][ny] == 1) continue;
            board[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
    return cnt;
}

int main() {
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int j = y1; j < y2; j++) 
            fill(board[j] + x1, board[j] + x2, 1);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!board[i][j]) {
                v.push_back(bfs(i, j));
            }
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (auto i : v)
        cout << i << ' ';
}