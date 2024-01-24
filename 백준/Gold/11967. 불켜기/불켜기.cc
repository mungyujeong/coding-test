#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define MAX_N 105

using namespace std;

int n, m;
vector<pair<int, int>> v[MAX_N][MAX_N];
int board[MAX_N][MAX_N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool is_movable(int x, int y) {
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
        if (board[nx][ny] == 2) {
            board[x][y] = 1;
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        v[x][y].push_back({a, b});
    }

    queue<pair<int, int>> Q;
    int x = 1;
    int y = 1;
    board[x][y] = 2;
    Q.push({x, y});

    do {
        tie(x, y) = Q.front(); Q.pop();

        // 해당 방에 있는 스위치로 불켜기
        for (auto p : v[x][y]) {
            if (!board[p.first][p.second]) {
                board[p.first][p.second] = 1;
                // 불 킨 방까지 이동할 수 있으면 추가
                for (int d = 0; d < 4; d++) {
                    int nx = p.first + dx[d];
                    int ny = p.second + dy[d];
                    if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
                    if (board[nx][ny] == 2) {
                        Q.push({nx, ny});
                        break;
                    } 
                }
            }
        }   
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
            if (board[nx][ny] == 1) {
                board[nx][ny] = 2;
                Q.push({nx, ny});
            }
        }
    } while (!Q.empty());

    int cnt = 0;
    for (int i = 1; i <= MAX_N; i++)
        for (int j = 1; j <= MAX_N; j++)
            if (board[i][j] > 0)
                cnt++;
    cout << cnt;
}