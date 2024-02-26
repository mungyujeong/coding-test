#include <iostream>

using namespace std;
using ll = long long;

ll n, r, c, answer;

void recursive(ll x, ll y, ll size) {
    if (x == r && y == c) {
        cout << answer << '\n';
        return;
    }

    ll half = size / 2;
    if (x <= r && r < x + size && y <= c && c < y + size) {
        recursive(x, y, half);
        recursive(x, y + half, half);
        recursive(x + half, y, half);
        recursive(x + half, y + half, half);
    }
    else answer += size * size;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r >> c;
    
    recursive(0, 0, (1 << n));
}