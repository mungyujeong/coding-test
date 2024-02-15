#include <iostream>
#include <unordered_map>

using namespace std;

int test_case, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test_case;
    while (test_case--) {

        cin >> n;

        unordered_map<string, int> m;
        int cnt = 1;
        for (int i = 0; i < n; i++) {
            string name, type;
            cin >> name >> type;
            m[type]++;
        }

        for (auto i : m)
            cnt *= (i.second + 1);
        cout << cnt - 1 << '\n';
    }
}