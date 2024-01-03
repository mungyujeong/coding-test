#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAX_N 25

using namespace std;

int n, cnt = 1;
int board[MAX_N][MAX_N];
queue<pair<int, int>> Q;
char c;
vector<int> v;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(int sx, int sy) {
    int answer = 0;
    Q.push({sx, sy});
    cnt++;
    while (!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[nx][ny] > 1 || board[nx][ny] == 0) continue;
            Q.push({nx, ny});
            board[nx][ny] = cnt;
            answer++;
        }
    }
    if (answer == 0) return 1;
    else return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            board[i][j] = c - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                v.push_back(bfs(i, j));
            }
        }
    }
    
    sort(v.begin(), v.end());
    cout << cnt - 1 << '\n';
    for (auto i : v) cout << i << '\n';
}