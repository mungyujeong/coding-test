#include <iostream>

#define MAX_N 1000'000

using namespace std;

int n;
int dp[MAX_N];

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
    }
    cout << dp[n];
}