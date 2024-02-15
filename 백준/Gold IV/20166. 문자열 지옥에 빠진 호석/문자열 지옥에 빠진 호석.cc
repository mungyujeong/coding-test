#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <tuple>

#define MAX_N 10

using namespace std;

int n, m, k;
char board[MAX_N][MAX_N];
unordered_map<string, int> result;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void bfs(string input, int x, int y) {
    int cnt = 0;
    int i;
    queue<tuple<int, int, int>> Q;

    Q.push({x, y, 0});
    while (!Q.empty()) {
        tie(x, y, i) = Q.front(); Q.pop();
        // cout << x << ' ' << y << ' ' << i << endl;
        if (i + 1 == input.size()) {
            cnt++;
            continue;
        }
        for (int d = 0; d < 8; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0) nx += n;
            if (ny < 0) ny += m;
            if (nx >= n) nx %= n;
            if (ny >= m) ny %= m;
            if (board[nx][ny] != input[i + 1]) continue;
            Q.push({nx, ny, i + 1});
        }
    }

    result[input] += cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    
    while (k--) {
        string input;
        cin >> input;
        if (result.find(input) == result.end()) {
            result[input] = 0;
            for (int i = 0; i < n; i++) 
                for (int j = 0; j < m; j++)
                    if (board[i][j] == input[0])
                        bfs(input, i, j);
        }
        cout << result[input] << '\n';
    }
}