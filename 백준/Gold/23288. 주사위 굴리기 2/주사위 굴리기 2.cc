#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define MAX_N 20

using namespace std;

int n, m, k, board[MAX_N][MAX_N], cur_x, cur_y, cur_d, score;
int up = 1;
int front = 5;
int R = 3;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void Move() {
    int nx = cur_x + dx[cur_d];
    int ny = cur_y + dy[cur_d];
    if (!InRange(nx, ny)) {
        nx = cur_x - dx[cur_d];
        ny = cur_y - dy[cur_d];
        cur_d = (cur_d + 2) % 4;
    }
    // right
    if (cur_d == 0) tie(up, front, R) = make_tuple(7 - R, front, up);
    // down
    else if (cur_d == 1) tie(up, front, R) = make_tuple(7 - front, up, R);
    // left
    else if (cur_d == 2) tie(up, front, R) = make_tuple(R, front, 7 - up);
    // up
    else tie(up, front, R) = make_tuple(front, 7 - up, R);

    cur_x = nx; cur_y = ny;
}

int BFS() {
    int x, y;
    x = cur_x; y = cur_y;
    queue<pair<int, int>> Q;
    bool visited[MAX_N][MAX_N] = {};
    int val = board[x][y];
    int cnt = board[x][y];

    Q.push({x, y});
    visited[x][y] = true;

    while (!Q.empty()) {
        tie(x, y) = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!InRange(nx, ny)) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] != val) continue;
            cnt += board[nx][ny];
            Q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }

    return cnt;
}

void Update() {
    int bottom = 7 - up;
    if (board[cur_x][cur_y] < bottom) {
        cur_d = (cur_d + 1) % 4;
    }
    else if (board[cur_x][cur_y] > bottom) {
        cur_d = (cur_d + 3) % 4;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    cur_x = cur_y = cur_d = 0;

    while (k--) {
        Move();
        score += BFS();
        Update();
    }

    cout << score;
    return 0;
}