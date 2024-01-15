#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

char board[12][6];
bool visited[12][6];
int answer;
bool is_finish;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int sx, int sy) {
    queue<pair<int, int>> Q;
    Q.push({sx, sy});
    visited[sx][sy] = true;
    int cnt = 0;
    int x, y;
    vector<pair<int, int>> path;

    while (!Q.empty()) {
        tie(x, y) = Q.front(); 
        path.push_back(Q.front());
        Q.pop();
        cnt++;
        char color = board[x][y];

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
            if (visited[nx][ny]) continue;
            if (color != board[nx][ny]) continue;
            visited[nx][ny] = true;
            Q.push({nx, ny});
        }        
    }

    if (cnt >= 4) {
        is_finish = false;
        for (auto p : path) {
            tie(x, y) = p;
            board[x][y] = '.';
        }
    }
}

void gravity() {
    for (int i = 0; i < 6; i++) {
        queue<char> q;
        for (int j = 11; j >= 0; j--) {
            if (board[j][i] != '.') {
                q.push(board[j][i]);
                board[j][i] = '.';
            }
        }
        for (int j = 11; j >= 0; j--) {
            if (!q.empty()) {
                board[j][i] = q.front();
                q.pop();
            }
        }
    }
}

int main() {
    for (int i = 0; i < 12; i++) 
        for (int j = 0; j < 6; j++)
            cin >> board[i][j];
    
    while (true) {
        is_finish = true;
        for (int i = 0; i < 12; i++)
            fill(visited[i], visited[i] + 6, 0);
        
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (board[i][j] == '.') continue;
                if (visited[i][j]) continue;
                bfs(i, j);
            }
        }

        if (is_finish) break;
        answer++;
        gravity();
        // for (int i = 0; i < 12; i++) {
        //     for (int j = 0; j < 6; j++) {
        //         cout << board[i][j];
        //     }
        //     cout << endl;
        // }
    }
    cout << answer;
}