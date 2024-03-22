#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 50

using namespace std;

int n, m, board[MAX_N][MAX_N];
// ←, ↖, ↑, ↗, →, ↘, ↓, ↙
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<pair<int, int>> special;

void Move(int d, int p) {
    vector<pair<int, int>> nxt;

    p = p % n;
    for (auto v : special) {
        int x, y;
        tie(x, y) = v;
        int nx = (x + dx[d] * p + n * p) % n;
        int ny = (y + dy[d] * p + n * p) % n;
        nxt.push_back({nx, ny});
    }

    special = nxt;
}

void Add() {
    int x, y;
    for (auto i : special) {
        tie(x, y) = i;
        board[x][y] += 1;
    }
}

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void Grow() {
    int x, y;
    for (auto i : special) {
        tie(x, y) = i;
        int cnt = 0;
        for (int d = 1; d < 8; d += 2) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!InRange(nx, ny)) continue;
            if (board[nx][ny] > 0) cnt++;
        }
        board[x][y] += cnt;
    }
    // special.clear();
}

void Update() {
    bool mapping[MAX_N][MAX_N] = {};
    int x, y;
    for (auto i : special) {
        tie(x, y) = i;
        mapping[x][y] = true;
    }

    special.clear();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (mapping[i][j]) continue;
            if (board[i][j] >= 2) {
                board[i][j] -= 2;
                special.push_back({i, j});
            }
        }
}

void Simulate(int d, int p) {
    Move(d, p);
    Add();
    Grow();
    Update();
}

int Height() {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cnt += board[i][j];
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    
    for (int i = n - 2; i < n; i++)
        for (int j = 0; j < 2; j++)
            special.push_back({i, j});
    
    for (int i = 0; i < m; i++) {
        int d, p;
        cin >> d >> p;
        Simulate(d - 1, p);
    }

    cout << Height();

    return 0;
}