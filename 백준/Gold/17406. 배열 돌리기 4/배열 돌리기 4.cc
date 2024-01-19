#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

#define MAX_N 50
#define MAX_K 6
using namespace std;

int board[MAX_N][MAX_N];
int n, m, k, answer = INT_MAX;
vector<tuple<int, int, int>> cmd;
int visited[MAX_K];
vector<int> order;
// 남 동 북 서
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void rotate() {
    int r, c, s;
    for (int i = 0; i < order.size(); i++) {
        tie(r, c, s) = cmd[order[i]];
        for (int j = s; j > 0; j--) {
            int sx = r - j;
            int ex = r + j;
            int sy = c - j;
            int ey = c + j;
            int d = 0;
            
            int x = sx; 
            int y = sy;
            while (true) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx == sx && ny == sy) break;
                if (nx > ex || nx < sx || ny > ey || ny < sy) {
                    d = (d + 1) % 4;
                    continue;
                }
                swap(board[x][y], board[nx][ny]);
                x = nx;
                y = ny;
            }
        }

    }
}

void backtracking(int depth) {
    if (depth == k) {
        rotate();

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                cnt += board[i][j];
            }
            answer = min(answer, cnt);
        }

        return;
    }

    int tmp[MAX_N][MAX_N];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            tmp[i][j] = board[i][j];

    for (int i = 0; i < k; i++) {
        if (visited[i]) continue;
        visited[i] = 1;
        order.push_back(i);
        backtracking(depth + 1);
        visited[i] = 0;
        order.pop_back();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                board[i][j] = tmp[i][j];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        int r, c, s;
        cin >> r >> c >> s;
        cmd.push_back({r - 1, c - 1, s});
    }

    backtracking(0);

    cout << answer;
}