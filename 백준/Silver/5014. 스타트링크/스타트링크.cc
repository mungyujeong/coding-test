#include <iostream>
#include <queue>

#define MAX_N 1000000

using namespace std;

int f, s, g, u, d;
queue<int> Q;
int board[MAX_N + 1];
int visited[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> f >> s >> g >> u >> d;

    Q.push(s);
    visited[s] = 1;

    while (!Q.empty()) {
        int x;
        x = Q.front(); Q.pop();
        int ux = x + u;
        int dx = x - d;
        if (ux <= f && !visited[ux]) {
            board[ux] = board[x] + 1;
            Q.push(ux);
            visited[ux] = 1;
        }
        if (dx >= 1 && !visited[dx]) {
            board[dx] = board[x] + 1;
            Q.push(dx);
            visited[dx] = 1;
        }
    }

    if (s == g) cout << 0;
    else if (board[g] == 0) cout << "use the stairs";
    else cout << board[g];
}