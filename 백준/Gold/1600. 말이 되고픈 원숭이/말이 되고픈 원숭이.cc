#include <iostream>
#include <queue>
#include <tuple>

#define MAX_W 200
#define MAX_K 30

using namespace std;

int k, w, h;
int board[MAX_W][MAX_W];
int dist[MAX_W][MAX_W][MAX_K + 1];
queue<tuple<int, int, int>> Q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int hx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int hy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs() {
    int x, y, jump;
    while (!Q.empty()) {
        tie(x, y, jump) = Q.front(); Q.pop();
        
        if (x == h - 1 && y == w - 1)
            return dist[x][y][jump];
        
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if (board[nx][ny] == 1) continue;
            if (dist[nx][ny][jump] > 0) continue;

            Q.push({nx, ny, jump});
            dist[nx][ny][jump] = dist[x][y][jump] + 1;
        }
        if (jump < k) {
            for (int d = 0; d < 8; d++) {
                int nx = x + hx[d];
                int ny = y + hy[d];
                if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                if (board[nx][ny] == 1) continue;
                if (dist[nx][ny][jump + 1] > 0) continue;

                Q.push({nx, ny, jump + 1});
                dist[nx][ny][jump + 1] = dist[x][y][jump] + 1;
            }
        }
    }

    return -1;
}

int main() {
    cin >> k;
    cin >> w >> h;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < k; i++)
        dist[0][0][i] = 0;

    Q.push({0, 0, 0});
    cout << bfs();
}