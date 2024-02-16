#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 1'000

using namespace std;
using ll = long long;

ll n, x, answer;
vector<ll> pl;
vector<ll> mi;

void solve(vector<ll> v) {
    while (v.size() > 1) {
        answer += *(v.end() - 1) * *(v.end() - 2);
        v.pop_back();
        v.pop_back();
    }
    if (!v.empty()) answer += v[0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1) answer++;
        else if (x > 0) pl.push_back(x);
        else mi.push_back(x);
    }
    sort(pl.begin(), pl.end());
    sort(mi.begin(), mi.end(), greater<ll>());

    solve(pl);
    solve(mi);

    cout << answer;
}