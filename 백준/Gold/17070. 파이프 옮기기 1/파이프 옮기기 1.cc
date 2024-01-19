#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 16

using namespace std;

int n, answer;
int board[MAX_N][MAX_N];
queue<tuple<int, int, int>> Q;
vector<vector<int>> d = {
    {0, 2},
    {1, 2},
    {0, 1, 2},
};

int dx[] = {0, 1, 1};
int dy[] = {1, 0, 1};

void bfs() {
    int dir, x, y;

    while (!Q.empty()) {
        tie(dir, x, y) = Q.front(); Q.pop();
        for (auto i : d[dir]) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[nx][ny] == 1) continue;
            if (i == 2) {
                if (board[x][ny] == 1 || board[nx][y] == 1) continue;   
            }
            if (nx == n - 1 && ny == n - 1) {
                answer++;
                continue;
            }
            Q.push({i, nx, ny});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    
    Q.push({0, 0, 1});
    bfs();
    cout << answer;
}