#include <iostream>
#include <climits>

#define MAX_N 11

using namespace std;

int test_case, n;
int dp[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test_case;
    while (test_case--) {
        cin >> n;
        fill(dp, dp + MAX_N + 1, INT_MAX);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for (int i = 4; i <= n; i++) 
            dp[i] = min(dp[i], dp[i - 1] + dp[i - 2] + dp[i - 3]);
        
        cout << dp[n] << '\n';
    }
}