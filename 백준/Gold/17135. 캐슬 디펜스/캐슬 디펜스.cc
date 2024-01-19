#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

#define MAX_N 20

using namespace std;

int board[MAX_N][MAX_N];
int n, m, d, answer, enemy;
vector<int> arrow;
// 서 북 동
int dx[] = {0, -1, 0};
int dy[] = {-1, 0, 1};

void simulate() {
    int result = 0;
    int x, y;
    int cnt = enemy;
    int tmp[MAX_N][MAX_N];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            tmp[i][j] = board[i][j];

    while (cnt) {
        // attack
        vector<pair<int, int>> v;
        for (int i = 0; i < arrow.size(); i++) {
            queue<pair<int, int>> Q;
            Q.push({n, arrow[i]});
            int visited[MAX_N][MAX_N] = {};
            bool attack = false;
            
            while (!Q.empty() && !attack) {
                tie(x, y) = Q.front(); Q.pop();
                if (visited[x][y] + 1 > d) continue;

                for (int dir = 0; dir < 3; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if (visited[nx][ny]) continue;
                    if (tmp[nx][ny] >= 1) {
                        tmp[nx][ny] += 1;
                        attack = true;
                        v.push_back({nx, ny});
                        break;
                    }
                    visited[nx][ny] = visited[x][y] + 1;
                    Q.push({nx, ny});
                }
            }
        }
        for (auto i : v) {
            tie(x, y) = i;
            if (tmp[x][y] != 0) {
                tmp[x][y] = 0;
                cnt--;
                result++;
            }
        }

        if (cnt == 0) break;

        // move
        for (int i = 0; i < m; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (j == 0) {
                    tmp[0][i] = 0;
                    continue;
                }
                if (j == n - 1 && tmp[j][i] >= 1) cnt--;
                tmp[j][i] = tmp[j - 1][i];
            }
        }
    }
    
    answer = max(answer, result);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) enemy++;
        }
    }

    vector<int> comb(m);
    fill(comb.end() - 3, comb.end(), 1);

    do {
        arrow.clear();
        for (int i = 0; i < m; i++) 
            if (comb[i]) 
                arrow.push_back(i);
        
        simulate();
    } while (next_permutation(comb.begin(), comb.end()));

    cout << answer;
}