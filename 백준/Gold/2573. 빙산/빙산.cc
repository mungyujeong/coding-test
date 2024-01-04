#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 300

using namespace std;

int n, m;
int iceberg[MAX_N][MAX_N];
int tmp[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<pair<int, int>> Q;

void update() {
    for (int i = 1; i < n - 1; i++) 
        for (int j = 1; j < m - 1; j++)
            tmp[i][j] = iceberg[i][j];
}

void melting() {
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (tmp[i][j] == 0) continue;
            
            for (int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (iceberg[i][j] == 0) break;
                if (tmp[nx][ny] == 0) {
                    iceberg[i][j] -= 1;
                }
            }
        }
    }

    update();
}

void bfs(int sx, int sy) {
    Q.push({sx, sy});
    visited[sx][sy] = 1;
    while (!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny]) continue;
            if (iceberg[nx][ny] == 0) continue;
            Q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> iceberg[i][j];

    update();
    
    int year = 0;
    bool all_zero = false;
    while(!all_zero) {
        year++;
        for (int i = 0; i < n; i++)
            fill(visited[i], visited[i] + MAX_N, 0);
        
        melting();

        int cnt = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (iceberg[i][j] == 0) continue;
                if (cnt > 1) break;
                if (!visited[i][j]) {
                    cnt++;
                    if (cnt > 1) break;
                    bfs(i, j);        
                }
            }
            if (cnt > 1) break;
        }
        if (cnt > 1) break;

        all_zero = true;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (iceberg[i][j] != 0) 
                    all_zero = false;
            }
        }
    }

    if (all_zero) cout << 0;
    else cout << year;
}