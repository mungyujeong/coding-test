#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int board[4][5][5][5], maze[5][5][5], answer = INT_MAX;
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

bool in_range(int x, int y, int z) {
    return 0 <= x && x < 5 && 0 <= y && y < 5 && 0 <= z && z < 5;
}

int simulate() {
    int visited[5][5][5] = {};
    int x, y, z;
    if (maze[0][0][0] == 0 || maze[4][4][4] == 0) return INT_MAX;

    queue<tuple<int, int, int>> Q;
    Q.push({0, 0, 0});
    visited[0][0][0] = 1;

    while (!Q.empty()) {
        tie(x, y, z) = Q.front(); Q.pop();
        for (int d = 0; d < 6; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            int nz = z + dz[d];
            if (!in_range(nx, ny, nz)) continue;
            if (nx == 4 && ny == 4 && nz == 4) 
                return visited[x][y][z];
            if (visited[nx][ny][nz]) continue;
            if (maze[nx][ny][nz] == 0) continue;
            Q.push({nx, ny, nz});
            visited[nx][ny][nz] = visited[x][y][z] + 1;
        }
    }

    return INT_MAX;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++) {
        // 0번
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                cin >> board[0][i][j][k];
        
        // 1번
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                board[1][i][j][k] = board[0][i][4 - k][j];
        
        // 2번
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                board[2][i][j][k] = board[1][i][4 - k][j];
        
        // 3번
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                board[3][i][j][k] = board[2][i][4 - k][j];
    }

    vector<int> order = {0, 1, 2, 3, 4};
    
    do {
        for (int tmp = 0; tmp < 1024; tmp++) {
            int brute = tmp;
            for (int floor = 0; floor < 5; floor++) {
                int dir = brute % 4;
                brute /= 4;
                for (int row = 0; row < 5; row++) 
                    for (int col = 0; col < 5; col++) 
                        maze[floor][row][col] = board[dir][order[floor]][row][col];
            }
            answer = min(answer, simulate());
        }
    } while (next_permutation(order.begin(), order.end()));

    if (answer == INT_MAX) answer = -1;
    cout << answer;
}