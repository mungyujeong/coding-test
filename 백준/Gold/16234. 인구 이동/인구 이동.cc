#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 50

using namespace std;

int n, L, R, board[MAX_N][MAX_N], answer, group[MAX_N][MAX_N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool Possible() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (!InRange(nx, ny)) continue;
                int diff = abs(board[nx][ny] - board[i][j]);
                if (L <= diff && diff <= R) return true;
            }
        }
    }

    return false;
}

void Initialize() {
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            group[i][j] = 0;
}

void BFS(int x, int y, int idx) {
    queue<pair<int, int>> Q;
    vector<pair<int, int>> v;

    int total = board[x][y];
    int cnt = 1;
    Q.push({x, y});
    v.push_back({x, y});
    group[x][y] = idx;

    while (!Q.empty()) {
        tie(x, y) = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!InRange(nx, ny)) continue;
            if (group[nx][ny]) continue;
            int diff = abs(board[nx][ny] - board[x][y]);
            if (L <= diff && diff <= R) {
                group[nx][ny] = idx;
                Q.push({nx, ny});
                total += board[nx][ny];
                v.push_back({nx, ny});
                cnt++;
            }
        }
    }
    
    for (auto p : v) {
        tie(x, y) = p;
        board[x][y] = total / cnt;
    }
}

void Simulate() {
    Initialize();
    int idx = 1;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {
            if (group[i][j]) continue;
            BFS(i, j, idx++);
        }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> L >> R;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    while (true) {
        if (Possible()){
            Simulate();
            answer++;
        } 
        else break;
    }

    cout << answer;
    return 0;
}