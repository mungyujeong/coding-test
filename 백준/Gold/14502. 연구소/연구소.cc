#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX_N 8

using namespace std;

int n, m, answer;
int board[MAX_N][MAX_N];
vector<pair<int, int>> virus;
vector<pair<int, int>> candidates;
queue<pair<int, int>> Q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs() {
    int x, y;
    while (!Q.empty()) {
        tie(x, y) = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] > 0) continue;
            board[nx][ny] = 2;
            Q.push({nx, ny});
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (board[i][j] == 0)
                cnt++;

    answer = max(answer, cnt);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) virus.push_back({i, j});
            else if (board[i][j] == 0) candidates.push_back({i, j});
        }
    }

    vector<int> comb(candidates.size(), 0);
    fill(comb.end() - 3, comb.end(), 1);

    int x, y;
    int tmp[MAX_N][MAX_N];

    do {
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                tmp[i][j] = board[i][j];

        for (int i = 0; i < candidates.size(); i++) {
            if (comb[i]) {
                // cout << i << ' ';
                tie(x, y) = candidates[i];
                board[x][y] = 1;
            }
        }

        for (int i = 0; i < virus.size(); i++) 
            Q.push(virus[i]);

        bfs();

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                board[i][j] = tmp[i][j];

    } while (next_permutation(comb.begin(), comb.end()));

    cout << answer;
}