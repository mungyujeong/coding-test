#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 10
#define X first
#define Y second

using namespace std;

int n, m;
char board[MAX_N][MAX_N];

// 아래 위 오른쪽 왼쪽
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
pair<int, int> blue, red, out;

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

pair<int, int> get_next_coord(int d, int x, int y) {
    while (true) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (!in_range(nx, ny)) break;
        if (board[nx][ny] == '#') break;
        if (board[nx][ny] == 'O') return make_pair(nx, ny);
        x = nx; y = ny;
    }

    return make_pair(x, y);
}

tuple<int, int, int, int> arrange(int d, int nrx, int nry, int nbx, int nby, int rx, int ry, int bx, int by) {
    if (d == 0) {
        if (rx > bx) nbx -= dx[d];
        else nrx -= dx[d];
    }
    else if (d == 1) {
        if (rx > bx) nrx -= dx[d];
        else nbx -= dx[d];
    }
    else if (d == 2) {
        if (ry > by) nby -= dy[d];
        else nry -= dy[d];
    }
    else {
        if (ry > by) nry -= dy[d];
        else nby -= dy[d];
    }

    return make_tuple(nrx, nry, nbx, nby);
}

int bfs() {
    int max_move = 10;
    // 방향 색깔
    bool visited[MAX_N][MAX_N][MAX_N][MAX_N] = {};
    queue<tuple<int, int, int, int, int>> Q;
    Q.push({blue.X, blue.Y, red.X, red.Y, 0});

    while (!Q.empty()) {
        int bx, by, rx, ry, t;
        tie(bx, by, rx, ry, t) = Q.front(); Q.pop();
        if (t == max_move) continue;
        // cout << "start: " << rx << ' ' << ry <<  ' ' << bx << ' ' << by << endl;

        for (int d = 0; d < 4; d++) {
            int nrx, nry, nbx, nby;
            // # 0을 만나면 stop
            // .이면 끝까지 이동
            tie(nbx, nby) = get_next_coord(d, bx, by);
            tie(nrx, nry) = get_next_coord(d, rx, ry);

            // blue가 나가면 continue
            if (make_pair(nbx, nby) == out) continue; 

            // 만약 같다면 방향에 따라 변경
            if (nrx == nbx && nry == nby) 
                tie(nrx, nry, nbx, nby) = arrange(d, nrx, nry, nbx, nby, rx, ry, bx, by);

            // cout << d << " red: " << nrx << ' ' << nry << ' ' << "blue: " << nbx << ' ' << nby << endl;
            // 두 구슬 모두 동시에 같은 방향, 같은 위치에 방문한 적이 있으면 continue
            if (visited[nbx][nby][nrx][nry]) continue;
            // red가 나가고 blue가 안나가면 시간 리턴
            if (make_pair(nrx, nry) == out) return t + 1;

            visited[nbx][nby][nrx][nry] = true;
            Q.push({nbx, nby, nrx, nry, t + 1});
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'B') {
                blue = make_pair(i, j);
                board[i][j] = '.';
            }
            else if (board[i][j] == 'R') {
                red = make_pair(i, j);
                board[i][j] = '.';
            }
            else if (board[i][j] == 'O') out = make_pair(i, j);
        }
    }

    cout << bfs();
}