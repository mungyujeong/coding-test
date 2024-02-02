#include <iostream>
#include <unordered_map>

using namespace std;
using ll = long long;

ll n, p, q;
unordered_map<ll, ll> dp;
unordered_map<ll, bool> check;

ll backtracking(ll depth) {
    if (depth == 0)
        return dp[0];

    ll result = 0;
    if (!check[depth / p]) {
        dp[depth / p] = backtracking(depth / p);
        check[depth / p] = true;
    }

    if (!check[depth / q]) {
        dp[depth / q] = backtracking(depth / q);
        check[depth / q] = true;
    }
    
    dp[depth] += dp[depth / q] + dp[depth / p];
    check[depth] = true;

    return dp[depth];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p >> q;

    dp[0] = 1;
    check[0] = true;
    
    cout << backtracking(n);
}