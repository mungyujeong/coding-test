#include <iostream>
#include <cmath>
#include <climits>

#define MAX_N 50'177

using namespace std;

int n, dp[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fill(dp, dp + n + 1, 100000);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j * j <= i; j++) 
            dp[i] = min(dp[i], dp[i - j * j] + 1);

    cout << dp[n];
}