#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <climits>

#define MAX_N 50

using namespace std;

int n, m, answer = INT_MAX;
int board[MAX_N][MAX_N];
vector<pair<int, int>> candidates;
queue<pair<int, int>> Q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int visited[MAX_N][MAX_N];

int bfs() {
    int x, y;    
    while (!Q.empty()) {
        tie(x, y) = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[nx][ny] == 1) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = visited[x][y] + 1;
            Q.push({nx, ny});
        }
    }

    // cout << "================bfs===================\n";
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) 
    //         cout << visited[i][j] << ' ';
    //     cout << endl;
    // }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != 1 && visited[i][j] == 0) return INT_MAX;
            cnt = max(cnt, visited[i][j] - 1);
        }
    }
    
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int t;
            cin >> t;
            if (t != 2) board[i][j] = t;
            else candidates.push_back({i, j});
        }
    }

    vector<int> comb(candidates.size(), 0);
    fill(comb.end() - m, comb.end(), 1);

    do {
        for (int i = 0; i < MAX_N; i++)
            fill(visited[i], visited[i] + MAX_N, 0);

        for (int i = 0; i < candidates.size(); i++) 
            if (comb[i]) {
                visited[candidates[i].first][candidates[i].second] = 1;
                Q.push(candidates[i]);
            }
            
        answer = min(answer, bfs());
    } while (next_permutation(comb.begin(), comb.end()));

    if (answer == INT_MAX) cout << -1;
    else cout << answer;
}