#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cmath>

#define MAX_N 64

using namespace std;

int n, q, board[MAX_N][MAX_N], max_size;
bool visited[MAX_N][MAX_N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void BFS(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    visited[x][y] = true;
    int cnt = 1;

    while (!Q.empty()) {
        tie(x, y) = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!InRange(nx, ny)) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] == 0) continue;
            visited[nx][ny] = true;
            cnt++;
            Q.push({nx, ny});
        }
    }

    max_size = max(max_size, cnt);
}

void Rotate(int x, int y, int level) {
    vector<vector<int>> v(level, vector<int>(level));
    for (int i = 0; i < level; i++)
        for (int j = 0; j < level; j++) 
            v[i][j] = board[x + i][y + j];
    
    for (int i = 0; i < level; i++)
        for (int j = 0; j < level; j++) 
            board[j + x][level - i - 1 + y] = v[i][j];
}

void Melt() {
    int nxt_board[MAX_N][MAX_N];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            nxt_board[i][j] = board[i][j];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!board[i][j]) continue;
            int cnt = 0;
            for (int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (!InRange(nx, ny) || board[nx][ny] == 0) continue;
                cnt++;
            }

            if (cnt < 3) nxt_board[i][j]--;
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = nxt_board[i][j];
}

void ReverseRotate(int x, int y, int level) {
    vector<vector<int>> v(level, vector<int>(level));
    for (int i = 0; i < level; i++)
        for (int j = 0; j < level; j++) 
            v[i][j] = board[x + i][y + j];
    
    for (int i = 0; i < level; i++)
        for (int j = 0; j < level; j++) 
            board[level - j - 1 + x][i + y] = v[i][j];
}

void Simulate(int level) {
    level = pow(2, level);
    
    for (int i = 0; i < n; i += level)
        for (int j = 0; j < n; j += level)
            Rotate(i, j, level);

    Melt();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    n = pow(2, n);

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    
    while (q--) {
        int level;
        cin >> level;
        Simulate(level);
    }


    int cnt = 0;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cnt += board[i][j];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visited[i][j] && board[i][j])
                BFS(i, j);
    
    cout << cnt << '\n' << max_size;
    return 0;
}