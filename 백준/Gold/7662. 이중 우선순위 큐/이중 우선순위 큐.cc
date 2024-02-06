#include <iostream>
#include <set>

using namespace std;
using ll = long long;

int test_case;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> test_case;
    while (test_case--) {
        int q;
        cin >> q;
        multiset<ll> s;
        while (q--) {
            char cmd;
            ll n;
            cin >> cmd >> n;

            if (cmd == 'I') s.insert(n);
            else {
                if (s.empty()) continue;
                if (n == 1) s.erase(--s.end());
                else s.erase(s.begin());
            }
        }

        if (s.empty()) cout << "EMPTY\n";
        else cout << *(--s.end()) << ' ' <<  *s.begin() << '\n';
    }
}