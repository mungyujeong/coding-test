#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 49

using namespace std;

int n, m, score, board[MAX_N][MAX_N], ax, ay;
vector<pair<int, int>> coord;

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void Attack(int d, int p) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int x, y;
    x = ax; y = ay;
    for (int i = 0; i < p; i++) {
        x += dx[d];
        y += dy[d];
        if (!InRange(x, y)) continue;
        board[x][y] = 0;
    }
}

void Fill() {
    int idx = 0;
    int tmp[MAX_N * MAX_N] = {};

    for (auto i : coord) {
        int x, y;
        tie(x, y) = i;
        if (board[x][y] == 0) continue;
        tmp[idx++] = board[x][y];
    }

    for (int i = 0; i < coord.size(); i++) {
        int x, y;
        tie(x, y) = coord[i];
        board[x][y] = tmp[i];
    }
}

bool Delete() {
    int val = -1;
    int cnt = 0;
    bool changed = false;
    vector<pair<int, int>> monster;

    for (auto i : coord) {
        int x, y;
        tie(x, y) = i;
        if (board[x][y] == 0) break;
        if (board[x][y] != val) {
            if (cnt >= 4) {
                // 이전 좌표 삭제
                changed = true;
                for (auto m : monster) {
                    int nx, ny;
                    tie(nx, ny) = m;
                    score += board[nx][ny];
                    board[nx][ny] = 0;
                }
            }

            // 다음 몬스터로 초기화
            cnt = 1;
            val = board[x][y];
            monster.clear();
            monster.push_back({x, y});
        }
        else if (board[x][y] == val) {
            cnt++;
            monster.push_back({x, y});
        }
    }

    if (cnt >= 4) {
        // 이전 좌표 삭제
        changed = true;
        for (auto m : monster) {
            int nx, ny;
            tie(nx, ny) = m;
            score += board[nx][ny];
            board[nx][ny] = 0;
        }
    }

    return changed;
}

void Update() {
    int idx = 0;
    int tmp[MAX_N * MAX_N] = {};
    int val = board[coord[0].first][coord[0].second];
    int cnt = 0;

    for (auto i : coord) {
        int x, y;
        tie(x, y) = i;
        if (board[x][y] == 0) {
            tmp[idx++] = cnt;
            if (idx == n * n) break;
            tmp[idx++] = val;
            if (idx == n * n) break;
            break;
        }
        if (board[x][y] == val) {
            cnt++;
        } 
        else {
            tmp[idx++] = cnt;
            if (idx == n * n) break;
            tmp[idx++] = val;
            if (idx == n * n) break;

            cnt = 1;
            val = board[x][y];
        }
    }

    for (int i = 0; i < coord.size(); i++) {
        int x, y;
        tie(x, y) = coord[i];
        board[x][y] = tmp[i];
    }
}

void Init() {
    int x, y, dist;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};
    x = ax; y = ay;
    dist = 0;

    while (x != 0 || y != 0) {
        for (int d = 0; d < 4; d++) {
            if (x == 0 && y == 0) break;
            if (d % 2 == 0) dist++;
            for (int i = 0; i < dist; i++) {
                x += dx[d];
                y += dy[d];
                if (!InRange(x, y)) {
                    x -= dx[d];
                    y -= dy[d];
                    break;
                };
                coord.push_back({x, y});
            }
        }    
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    ax = ay = n / 2;

    Init();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];


    for (int i = 0; i < m; i++) {
        int d, p;
        cin >> d >> p;

        Attack(d - 1, p);
        Fill();

        while (Delete())
            Fill();
        Update();
    }

    cout << score;
    return 0;
}