#include <iostream>

#define MAX_N 1'000

using namespace std;

string a, b, answer;
int board[MAX_N + 1][MAX_N + 1];
int x, y;
int dx[] = {-1, 0};
int dy[] = {0, -1};

bool move() {
    for (int d = 0; d < 2; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (board[nx][ny] == board[x][y]) {
            x = nx;
            y = ny;
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a;
    cin >> b;

    x = a.size();
    y = b.size();

    for (int i = 1; i <= x; i++) 
        for (int j = 1; j <= y; j++) 
            if (a[i - 1] == b[j - 1])
                board[i][j] = board[i - 1][j - 1] + 1;
            else 
                board[i][j] = max(board[i - 1][j], board[i][j - 1]);
    
    while (x != 0 && y != 0) {
        if (!move()) {
            x -= 1;
            y -= 1;
            answer += a[x];
        }
    }

    cout << answer.size() << '\n';
    for (int i = answer.size() - 1; i >= 0; i--)
        cout << answer[i];
}