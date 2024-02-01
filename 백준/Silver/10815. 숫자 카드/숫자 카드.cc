#include <iostream>
#include <unordered_map>

using namespace std;
using ll = long long;

ll n, m, x;
unordered_map<ll, bool> map;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        map[x] = true;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        if (map[x]) cout << 1 << ' ';
        else cout << 0 << ' ';
    }
}