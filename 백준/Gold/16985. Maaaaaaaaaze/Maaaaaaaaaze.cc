#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

int board[5][5][5], answer = INT_MAX;
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
bool selected[5];
vector<vector<vector<int>>> rotate_case[5];
vector<vector<vector<int>>> maze;
vector<vector<int>> after(5, vector<int>(5, 0));
vector<vector<int>> origin(5, vector<int>(5, 0));

void rotate(int floor, int rotate_times) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            after[i][j] = origin[i][j] = board[floor][i][j];
    
    for (int i = 0; i < rotate_times; i++) {
        for (int x = 0; x < 5; x++)
            for (int y = 0; y < 5; y++)
                after[y][5 - x - 1] = origin[x][y];
        
        for (int x = 0; x < 5; x++)
            for (int y = 0; y < 5; y++)
                origin[x][y] = after[x][y];
    }

    rotate_case[floor].push_back(after);
}

bool in_range(int x, int y, int z) {
    return 0 <= x && x < 5 && 0 <= y && y < 5 && 0 <= z && z < 5;
}

void bfs(tuple<int, int, int> st, tuple<int, int, int> en) {
    int x, y, z, ex, ey, ez;
    tie(x, y, z) = st;
    tie(ex, ey, ez) = en;
    if (maze[x][y][z] == 0 || maze[ex][ey][ez] == 0) return;

    queue<tuple<int, int, int>> Q;
    int visited[5][5][5] = {};
    Q.push({x, y, z});
    visited[x][y][z] = 1;

    while (!Q.empty()) {
        tie(x, y, z) = Q.front(); Q.pop();
        for (int d = 0; d < 6; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            int nz = z + dz[d];
            if (!in_range(nx, ny, nz)) continue;
            if (maze[nx][ny][nz] == 0) continue;
            if (visited[nx][ny][nz]) continue;
            visited[nx][ny][nz] = visited[x][y][z] + 1;
            Q.push({nx, ny, nz});
        }
    }

    if (visited[ex][ey][ez] != 0)
        answer = min(answer, visited[ex][ey][ez]);
}

void simulate() {
    vector<tuple<int, int, int>> st = {{0, 0, 0}, {0, 4, 0}, {0, 0, 4}, {0, 4, 4}};
    vector<tuple<int, int, int>> en = {{4, 4, 4}, {4, 0, 4}, {4, 4, 0}, {4, 0, 0}};
    
    for (int i = 0; i < 4; i++) 
        bfs(st[i], en[i]);
}

void backtracking(int depth) {
    if (depth == 5) {
        simulate();
        return;
    }
    
    for (int floor = 0; floor < 5; floor++) {
        if (selected[floor]) continue;
        selected[floor] = true;
        for (int r = 0; r < 4; r++) {
            maze.push_back(rotate_case[floor][r]);
            backtracking(depth + 1);
            maze.pop_back();
        }
        selected[floor] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int floor = 0; floor < 5; floor++) 
        for (int row = 0; row < 5; row++) 
            for (int col = 0; col < 5; col++) 
                cin >> board[floor][row][col];
    
    for (int floor = 0; floor < 5; floor++)
        // 각 층마다 회전 후 저장
        for (int rotate_times = 0; rotate_times < 4; rotate_times++) 
            rotate(floor, rotate_times);

    // 5개 층 나열하기
    backtracking(0);

    if (answer == INT_MAX) cout << -1;
    else cout << answer - 1 ;
}