#include <iostream>

#define MAX_N 1'500'002

using namespace std;

int n, dp[MAX_N], times[MAX_N], price[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> times[i] >> price[i];
    
    int max_val = 0;
    for (int i = n; i >= 1; i--) {
        int t = i + times[i];
        if (t > n + 1) dp[i] = max_val;
        else {
            dp[i] = max(dp[t] + price[i], max_val);
            max_val = dp[i];
        }
    }

    cout << max_val;
}