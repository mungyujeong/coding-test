#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 100

using namespace std;

int n;
int board[MAX_N + 1][MAX_N + 1];
int nested_board[MAX_N + 1][MAX_N + 1];
int visited[MAX_N  + 1][MAX_N + 1];
int nested_visited[MAX_N + 1][MAX_N + 1];
queue<pair<int, int>> Q;
queue<pair<int, int>> NQ;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int color, int sx, int sy) {
    // 일반인
    Q.push({sx, sy});
    visited[sx][sy] = 1;
    while (!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[nx][ny] != color || visited[nx][ny]) continue;
            Q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }
}

void nested_bfs(int color, int sx, int sy) {
    NQ.push({sx, sy});
    nested_visited[sx][sy] = 1;
    while (!NQ.empty()) {
        int x, y;
        tie(x, y) = NQ.front(); NQ.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (nested_board[nx][ny] != color || nested_visited[nx][ny]) continue;
            NQ.push({nx, ny});
            nested_visited[nx][ny] = 1;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n ; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            if (str[j] == 'R') {
                board[i][j] = 1;
                nested_board[i][j] = 1;
            } else if (str[j] == 'G') {
                board[i][j] = 2;
                nested_board[i][j] = 1;
            } else {
                board[i][j] = 3;
                nested_board[i][j] = 3;
            }
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                bfs(board[i][j], i, j);
                cnt++;
            }
        }
    }
    cout << cnt << ' ';

    cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!nested_visited[i][j]) {
                nested_bfs(nested_board[i][j], i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
}