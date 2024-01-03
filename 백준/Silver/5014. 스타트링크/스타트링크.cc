#include <iostream>
#include <queue>

#define MAX_N 1000000

using namespace std;

int f, s, g, u, d;
queue<int> Q;
int board[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> f >> s >> g >> u >> d;

    fill(board + 1, board + f + 1, -1);
    
    Q.push(s);
    board[s] = 0;

    while (!Q.empty()) {
        int x;
        x = Q.front(); Q.pop();
        for (auto nx : {x + u, x - d}) {
            if (nx < 1 || nx > f || board[nx] != -1) continue;
            Q.push(nx);
            board[nx] = board[x] + 1;
        }
    }

    if (board[g] == -1) cout << "use the stairs";
    else cout << board[g];
}