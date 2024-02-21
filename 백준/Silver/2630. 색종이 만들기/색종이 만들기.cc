#include <iostream>

#define MAX_N 128

using namespace std;

int n, board[MAX_N][MAX_N], white, blue;

void recursive(int len, int x, int y) {
    int color = board[x][y];
    if (len == 1) {
        if (color == 0) white++;
        else blue++;
        return;
    }

    for (int i = x; i < x + len; i++) {
        for (int j = y; j < y + len; j++) {
            if (color != board[i][j]) {
                len /= 2;
                recursive(len, x, y);
                recursive(len, x + len, y);
                recursive(len, x, y + len);
                recursive(len, x + len, y + len);
                return;
            }
        }
    }

    if (color == 0) white++;
    else blue++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    // 0 white 
    // 1 blue
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    
    recursive(n, 0, 0);

    cout << white << '\n' << blue;
}