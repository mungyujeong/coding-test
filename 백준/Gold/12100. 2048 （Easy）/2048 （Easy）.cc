#include <iostream>

#define MAX_N 30

using namespace std;

int n;
int board[MAX_N][MAX_N];

int answer;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void move(int dir) {
    if (dir == 0) {
        for (int col = 0; col < n; col++) {
            for (int row = n - 1; row >= 0; row--) {
                if (board[row][col] == 0) continue;
                int x = row;
                int y = col;
                int nx = x - dx[dir];
                int ny = y - dy[dir];
                while (InRange(nx, ny)) {
                    if (board[nx][ny] != 0) break;
                    nx -= dx[dir];
                    ny -= dy[dir];
                }
                if (board[nx][ny] == board[row][col]) {
                    board[row][col] *= 2;
                    board[nx][ny] = 0;
                }
            }

            for (int row = n - 1; row >= 0; row--) {
                if (board[row][col] == 0) continue;
                int x = row;
                int y = col;
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                while (InRange(nx, ny)) {
                    if (board[nx][ny] != 0) break;
                    board[nx][ny] = board[x][y];
                    board[x][y] = 0;
                    x = nx;
                    y = ny;
                    nx += dx[dir];
                    ny += dy[dir];
                }
            }
        }
    }
    else if (dir == 1) {
        for (int col = 0; col < n; col++) {
            for (int row = 0; row < n; row++) {
                if (board[row][col] == 0) continue;
                int x = row;
                int y = col;
                int nx = x - dx[dir];
                int ny = y - dy[dir];
                while (InRange(nx, ny)) {
                    if (board[nx][ny] != 0) break;
                    nx -= dx[dir];
                    ny -= dy[dir];
                }
                if (board[nx][ny] == board[row][col]) {
                    board[row][col] *= 2;
                    board[nx][ny] = 0;
                }
            }

            for (int row = 0; row < n; row++) {
                if (board[row][col] == 0) continue;
                int x = row;
                int y = col;
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                while (InRange(nx, ny)) {
                    if (board[nx][ny] != 0) break;
                    board[nx][ny] = board[x][y];
                    board[x][y] = 0;
                    x = nx;
                    y = ny;
                    nx += dx[dir];
                    ny += dy[dir];
                }
            }
        }
    }
    else if (dir == 2) {
        for (int row = 0; row < n; row++) {
            for (int col = n - 1; col >= 0; col--) {
                if (board[row][col] == 0) continue;
                int x = row;
                int y = col;
                int nx = x - dx[dir];
                int ny = y - dy[dir];
                while (InRange(nx, ny)) {
                    if (board[nx][ny] != 0) break;
                    nx -= dx[dir];
                    ny -= dy[dir];
                }
                if (board[nx][ny] == board[row][col]) {
                    board[row][col] *= 2;
                    board[nx][ny] = 0;
                }
            }

            for (int col = n - 1; col >= 0; col--) {
                if (board[row][col] == 0) continue;
                int x = row;
                int y = col;
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                while (InRange(nx, ny)) {
                    if (board[nx][ny] != 0) break;
                    board[nx][ny] = board[x][y];
                    board[x][y] = 0;
                    x = nx;
                    y = ny;
                    nx += dx[dir];
                    ny += dy[dir];
                }
            }
        }
    } 
    else {
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] == 0) continue;
                int x = row;
                int y = col;
                int nx = x - dx[dir];
                int ny = y - dy[dir];
                while (InRange(nx, ny)) {
                    if (board[nx][ny] != 0) break;
                    nx -= dx[dir];
                    ny -= dy[dir];
                }
                if (board[nx][ny] == board[row][col]) {
                    board[row][col] *= 2;
                    board[nx][ny] = 0;
                }
            }

            for (int col = 0; col < n; col++) {
                if (board[row][col] == 0) continue;
                int x = row;
                int y = col;
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                while (InRange(nx, ny)) {
                    if (board[nx][ny] != 0) break;
                    board[nx][ny] = board[x][y];
                    board[x][y] = 0;
                    x = nx;
                    y = ny;
                    nx += dx[dir];
                    ny += dy[dir];
                }
            }
        }
    }
}

void back_tracking(int depth) {
    if (depth == 5) {
        for (int i = 0; i < n; i++)     
            for (int j = 0; j < n; j++)
                answer = max(answer, board[i][j]);
        
        return;
    }

    int tmp[MAX_N][MAX_N];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[i][j] = board[i][j];

    for (int d = 0; d < 4; d++) {
        move(d);
        back_tracking(depth + 1);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = tmp[i][j];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    
    back_tracking(0);

    cout << answer;
}