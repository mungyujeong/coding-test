#include <iostream>
#include <queue>
#include <tuple>
#include <string>

#define MAX_W 1000

using namespace std;

int test_case, w, h, curr_x, curr_y;
string str;
int board[MAX_W][MAX_W];
int visited[MAX_W][MAX_W];
int fire[MAX_W][MAX_W];
queue<pair<int, int>> Q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool bfs() {
    while (!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front(); Q.pop();
        visited[x][y] = 1;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
                cout << board[x][y] + 1 << '\n';
                return true;
            }
            if (visited[nx][ny]) continue;
            if (board[nx][ny] < 0) continue;
            if (board[nx][ny] <= board[x][y] + 1 && board[nx][ny] != 0) continue;
            if (fire[nx][ny]) continue;
            visited[nx][ny] = 1;
            Q.push({nx, ny});
            board[nx][ny] = board[x][y] + 1;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test_case;
    while (test_case--) {
        for (int i = 0; i < h; i++) {
            fill(visited[i], visited[i] + w, 0);
            fill(board[i], board[i] + w, 0);
            fill(fire[i], fire[i] + w, 0);
        }

        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            cin >> str;
            for (int j = 0; j < w; j++) {
                if (str[j] == '#') {
                    board[i][j] = -1;
                } else if (str[j] == '*') {
                    board[i][j] = 0;
                    fire[i][j] = 1;
                    Q.push({i, j});
                } else if (str[j] == '@') {
                    board[i][j] = 0;
                    curr_x = i;
                    curr_y = j;
                } else {
                    board[i][j] = 0;
                }
            }
        }

        while (!Q.empty()) {
            int x, y;
            tie(x, y) = Q.front(); Q.pop();
            visited[x][y] = 1;
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                if (visited[nx][ny]) continue;
                if (board[nx][ny] < 0) continue;
                visited[nx][ny] = 1;
                Q.push({nx, ny});
                board[nx][ny] = board[x][y] + 1;
            }
        }
        
        Q.push({curr_x, curr_y});
        for (int i = 0; i < h; i++) {
            fill(visited[i], visited[i] + w, 0);
        }
        board[curr_x][curr_y] = 0;
        if(!bfs()) {
            cout << "IMPOSSIBLE\n";
        }
    }
}