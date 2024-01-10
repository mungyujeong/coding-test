#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <climits>

#define MAX_N 8

using namespace std;

int n, m, answer = INT_MAX;
int board[MAX_N][MAX_N];
vector<pair<int, int>> v;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<vector<vector<int>>> cctv = {
    {{0}, {1}, {2}, {3}},
    {{0, 2}, {1, 3}},
    {{0, 1}, {1, 2}, {2, 3}, {3, 0}},
    {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},
    {{0, 1, 2, 3}},
};

void dfs(int depth) {
    if (depth == v.size()) {
        int cnt = 0;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                if (board[i][j] == 0)
                    cnt++;
        
        answer = min(answer, cnt);
        return;
    }

    int sx, sy;
    tie(sx, sy) = v[depth];
    vector<vector<int>> dir = cctv[board[sx][sy] - 1];

    for (auto i : dir) { // case 선택
        int tmp[MAX_N][MAX_N];
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                tmp[i][j] = board[i][j];

        for (auto j : i) { // 한가지 방향 선택해서 채우기
            queue<pair<int, int>> Q;
            Q.push({sx, sy});
            while (!Q.empty()) {
                int x, y;
                tie(x, y) = Q.front(); Q.pop();
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (board[nx][ny] == 6) break;
                if (1 <= board[nx][ny] && board[nx][ny] <= 5) {
                    Q.push({nx, ny});
                    continue;
                }
                Q.push({nx, ny});
                board[nx][ny] = 7;
            }
        }
        // cout << "==================\n";
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) 
        //         cout << board[i][j] << ' ';
        //     cout << endl;
        // }
        // cout << "==================\n";

        dfs(depth + 1);

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                board[i][j] = tmp[i][j];
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] != 0 && board[i][j] != 6) {
                v.push_back({i, j});
            }
        }
    }

    dfs(0);
    
    cout << answer;
}