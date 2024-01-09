#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

char board[5][5];
vector<int> comb(25, 0);
int answer;
int selected[5][5];
int visited[5][5];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool bfs(vector<pair<int, int>> v) {
    for (int i = 0; i < 5; i++) {
        fill(visited[i], visited[i] + 5, 0);
        fill(selected[i], selected[i] + 5, 0);
    }
    
    int x, y;
    for (auto i : v) {
        tie(x, y) = i;
        selected[x][y] = 1;
    }

    queue<pair<int, int>> Q;
    tie(x, y) = v[0];
    Q.push({x, y});
    visited[x][y] = 1;
    while (!Q.empty()) {
        tie(x, y) = Q.front(); Q.pop();
        visited[x][y] = 1;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            if (visited[nx][ny] == 1 || selected[nx][ny] != 1) continue;
            Q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }

    for (auto i : v) {
        tie(x, y) = i;
        if (visited[x][y] == 0) 
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> board[i][j];
    
    for (int i = 18; i < 25; i++)
        comb[i] = 1;

    do {
        vector<pair<int, int>> v;
        int cnt = 0;
        for (int i = 0; i < 25; i++) {
            if (comb[i] == 1) {
                int x = i / 5;
                int y = i % 5;
                v.push_back({x, y});
                if (board[x][y] == 'S')
                    cnt++;
            }
        }

        if (bfs(v)) {
            if (cnt >= 4)
                answer++;
        }
    } while (next_permutation(comb.begin(), comb.end()));

    cout << answer;
}