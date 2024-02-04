#include <iostream>
#include <algorithm>

#define MAX_N 1'000

using namespace std;

int n, P[MAX_N], answer, dp[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> P[i];   
    
    sort(P, P + n);

    answer = dp[0] = P[0];   
    for (int i = 1; i < n; i++) {
        dp[i] += P[i] + dp[i - 1];
        answer += dp[i];
    }
    cout << answer;
}