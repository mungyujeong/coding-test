#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 1000
#define MAX_K 10

using namespace std;

int n, m, k;
char board[MAX_N][MAX_N];
int dist[MAX_N][MAX_N][MAX_K + 1];
queue<tuple<int, int, int>> Q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs() {
    int x, y, broken;
    while (!Q.empty()) {
        tie(x, y, broken) = Q.front(); Q.pop();

        if (x == n - 1 && y == m - 1)
            return dist[x][y][broken];
        
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
                dist[nx][ny][broken] = dist[x][y][broken] + 1;
                Q.push({nx, ny, broken});
            }
            if (board[nx][ny] == '1' && broken < k && dist[nx][ny][broken + 1] == -1) {
                dist[nx][ny][broken + 1] = dist[x][y][broken] + 1;
                Q.push({nx, ny, broken + 1});
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            fill(dist[i][j], dist[i][j] + MAX_K + 1, -1);
    
    for (int i = 0; i <= k; i++)
        dist[0][0][i] = 1;
    
    Q.push({0, 0, 0});
    cout << bfs();
}