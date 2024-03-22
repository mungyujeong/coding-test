#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define MAX_N 20
#define BLANK -2
#define ROCK -1

using namespace std;

int n, m, score, board[MAX_N][MAX_N];
tuple<int, int, int, int> bomb;
vector<pair<int, int>> red, selected;
bool visited[MAX_N][MAX_N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void Update(tuple<int, int, int, int> tmp) {
    int C, R, max_row, min_col;
    tie(C, R, max_row, min_col) = tmp;
}

void BFS(int x, int y) {
    tuple<int, int, int, int> tmp;
    vector<pair<int, int>> coord; // 좌표값들 저장
    int C, R, max_row, min_col;
    queue<pair<int, int>> Q;
    
    int color = board[x][y];

    Q.push({x, y});
    visited[x][y] = true;
    C = 1; R = 0;
    coord.push_back({x, y});
    max_row = x; min_col = y;

    while (!Q.empty()) {
        tie(x, y) = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!InRange(nx, ny)) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] <= ROCK) continue;
            if (board[nx][ny] == 0) {
                R++;
            }
            else if (board[nx][ny] != color) continue;

            Q.push({nx, ny});
            visited[nx][ny] = true;
            coord.push_back({nx, ny});
            C++;

            // 기준점 갱신
            if (board[nx][ny] == color) {
                if (max_row == nx) {
                    if (min_col > ny) {
                        max_row = nx;
                        min_col = ny;
                    }
                }
                else if (max_row > nx) {
                    max_row = nx;
                    min_col = ny;
                }
            }
        }
    }

    // 결과
    tmp = make_tuple(C, R, max_row, min_col);

    if (C > 1) {
        int a, b, c, d;
        tie(a, b, c, d) = bomb;
        if (a == C) {
            if (b == R) {
                if (c == max_row) {
                    if (d < min_col) {
                        bomb = tmp;
                        selected = coord;
                    }
                }   
                else if (c < max_row) {
                    bomb = tmp;
                    selected = coord;
                }
            }
            else if (b < R) {
                bomb = tmp;
                selected = coord;
            }
        }
        else if (a < C) {
            bomb = tmp;
            selected = coord;
        }
    }
}

void RedInit() {
    int x, y;
    for (auto r : red) {
        tie (x, y) = r;
        visited[x][y] = false;
    }
}

bool FindBomb() {
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {
            if (board[i][j] <= 0) continue;
            if (visited[i][j]) continue;
            RedInit();
            BFS(i, j);
        }
    
    if (bomb == make_tuple(-1, -1, -1, -1)) return false;
    else return true;
}

void Initialize() {
    bomb = make_tuple(-1, -1, -1, -1);
    red.clear();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) red.push_back({i, j});
            visited[i][j] = false;
        }
}

void Delete() {
    int x, y;
    for (auto s : selected) {
        tie(x, y) = s;
        board[x][y] = BLANK;
    }
    int C = selected.size();
    score += C * C;
}

void Gravity() {
    for (int col = 0; col < n; col++) {
        int idx = 0;
        int tmp[MAX_N];
        fill(tmp, tmp + n, -2);

        for (int row = n - 1; row >= 0; row--) {
            if (board[row][col] == BLANK) continue;
            if (board[row][col] == ROCK) {
                idx = n - 1 - row;
                tmp[idx++] = ROCK;
            }
            else tmp[idx++] = board[row][col];
        }

        for (int row = n - 1; row >= 0; row--)
            board[row][col] = tmp[n - 1 - row];
    }
}

void Rotate() {
    int nxt_board[MAX_N][MAX_N];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            nxt_board[i][j] = board[i][j];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[n - 1 - j][i] = nxt_board[i][j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    while (true) {
        Initialize();
        if (!FindBomb()) break;
        Delete();
        Gravity();
        Rotate();
        Gravity();
    }

    cout << score;
    return 0;
}