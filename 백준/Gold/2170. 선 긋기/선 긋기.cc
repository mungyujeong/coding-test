#include <iostream>
#include <algorithm>
#include <vector>

#define OFFSET 1'000'000'000

using namespace std;
using ll = long long;
ll n, x, y, answer, st, en;
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({x + OFFSET, y + OFFSET});
    }

    sort(v.begin(), v.end());

    tie(st, en) = v[0];
    answer += en - st;
    for (int i = 1; i < v.size(); i++) {
        tie (x, y) = v[i];
        if (x <= en && en < y) {
            answer += y - en;
            en = y;
        }
        else if (x > en) {
            st = x; en = y;
            answer += en - st;
        }
    }
    cout << answer;
}