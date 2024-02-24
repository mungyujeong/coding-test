#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m, x, y, answer;
int board[101], visited[101];

int bfs() {
    queue<pair<int, int>> Q;
    int cur, cnt;

    Q.push({1, 0});
    visited[1] = 1;

    while (!Q.empty()) {
        tie(cur, cnt)= Q.front(); Q.pop();
        if (cur == 100) return cnt;

        for (auto i : {1, 2, 3, 4, 5, 6}) {
            if (cur + i > 100) continue;
            if (visited[cur + i]) continue;
            visited[cur + i] = 1;

            int nxt = board[cur + i];
            if (nxt == 0) nxt = cur + i;
            else if (visited[nxt]) continue;

            visited[nxt] = 1;
            Q.push({nxt, cnt + 1});    
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        board[x] = y;
    }

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        board[x] = y;
    }

    cout << bfs();
}