#include <iostream>

#define MAX_N 100

using namespace std;
using ll = long long;

ll t, n, dp[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= 100; i++) 
        dp[i] = dp[i - 2] + dp[i - 3];

    while (t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
}