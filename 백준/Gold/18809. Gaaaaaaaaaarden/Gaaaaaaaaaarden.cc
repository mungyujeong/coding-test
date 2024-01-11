#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
#include <tuple>

#define MAX_N 50

using namespace std;

int n, m, g, r, answer = INT_MIN;
int board[MAX_N][MAX_N];
vector<pair<int, int>> area;
queue<tuple<int, int, int, int>> Q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
pair<int, int> visited[MAX_N][MAX_N];

int bfs() {
    int color, times, x, y;
    while (!Q.empty()) {
        tie(x, y, color, times) = Q.front(); Q.pop();
        if (visited[x][y].first == 3) continue;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] == 0) continue;

            int nxt_color, nxt_time;
            tie(nxt_color, nxt_time) = visited[nx][ny];

            if (nxt_color == 3) continue;
            if (nxt_time == times + 1 && nxt_color != color) {
                visited[nx][ny] = {3, times + 1};
                continue;
            }
            if (nxt_time != -1 && nxt_time <= times + 1) continue;
            if (nxt_color > 0) continue;

            visited[nx][ny] = {color, times + 1};
            Q.push({nx, ny, color, times + 1});
        }
    }   


    int cnt = 0;
    // cout << "==============\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j].first == 3)
                cnt++;
            // cout << visited[i][j].first << ' ' << visited[i][j].second << ' ';
        }
        // cout << endl;
    }
    // cout << "==============" << cnt << endl;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> g >> r;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                area.push_back({i, j});
                cnt++;
            }
        }
    }

    vector<int> comb(cnt, 0);
    for (int i = 0; i < g; i++)
        comb[i] = 1;
    for (int i = g; i < g + r; i++)
        comb[i] = 2;
    sort(comb.begin(), comb.end());

    do {
        for (int i = 0; i < MAX_N; i++)
            fill(visited[i], visited[i] + MAX_N, make_pair(0, -1));

        for (int i = 0; i < cnt; i++) {
            int x, y;
            tie(x, y) = area[i];

            if (comb[i] == 1) {
                // cout << "g: " << x << ' ' << y << '\n';
                Q.push({x, y, 1, 0});
                visited[x][y] = {1, 0};
            }
            if (comb[i] == 2) {
                // cout << "r: " << x << ' ' << y << '\n';
                Q.push({x, y, 2, 0});
                visited[x][y] = {2, 0};
            }
        }

        answer = max(answer, bfs());
    } while (next_permutation(comb.begin(), comb.end()));

    cout << answer;
}