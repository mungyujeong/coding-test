#include <iostream>

#define MAX_N 1025

using namespace std;

int n, m, board[MAX_N][MAX_N], dp[MAX_N][MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
            dp[i][j] = dp[i][j - 1] + board[i][j];
        }
    }
    
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        int answer = 0;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int h = x1; h <= x2; h++) 
            answer += dp[h][y2] - dp[h][y1 - 1];
        
        cout << answer << '\n';
    }
}