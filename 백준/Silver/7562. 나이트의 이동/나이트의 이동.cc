#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 300

using namespace std;

int l, test_case, curr_x, curr_y, target_x, target_y;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int board[MAX_N][MAX_N];
queue<pair<int, int>> Q;
int answer;

void bfs() {
    while(!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front(); Q.pop();
        for (int d = 0; d < 8; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
            if (board[nx][ny] > 0) continue;
            Q.push({nx, ny});
            board[nx][ny] = board[x][y] + 1;
        }
    }
}

int main() {
    cin >> test_case;
    while (test_case--) {
        cin >> l;
        cin >> curr_x >> curr_y;
        cin >> target_x >> target_y;
        Q.push({curr_x, curr_y});

        for (int i = 0; i < l; i++) 
            fill(board[i], board[i] + l, 0);

        if (target_x == curr_x && target_y == curr_y)
            cout << 0 << '\n';
        else {
            bfs();
            cout << board[target_x][target_y] << '\n';
        }
    }
}