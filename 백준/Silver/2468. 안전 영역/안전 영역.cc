#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 100

using namespace std;

int n, answer;
int board[MAX_N][MAX_N];
int flood[MAX_N][MAX_N];
queue<pair<int, int>> Q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int sx, int sy, int height) {
    Q.push({sx, sy});
    flood[sx][sy] = 1;
    while (!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[nx][ny] < height) continue;
            if (flood[nx][ny]) continue;
            Q.push({nx, ny});
            flood[nx][ny] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int h = 1; h <= 100; h++) {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            fill(flood[i], flood[i] + n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] >= h && flood[i][j] == 0) {
                    bfs(i, j, h);
                    cnt++;
                }
            }
        }
        
        answer = max(answer, cnt);
    }

    cout << answer;
}