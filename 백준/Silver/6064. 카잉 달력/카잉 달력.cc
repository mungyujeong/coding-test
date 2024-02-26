#include <iostream>
#include <vector>

using namespace std;

int test_case;

int get_idx(int max_year, int target, int min_val, int diff) {
    int tmp = min_val;
    int idx = 0;
    int limit = max_year;
    while (limit--) {
        if (target == tmp) return idx;
        idx++;
        tmp = tmp - diff;
        if (tmp <= 0) tmp += max_year;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test_case;
    while (test_case--) {
        int answer = 0;
        int m, n, x, y, idx;

        vector<int> v;

        cin >> m >> n >> x >> y;
        if (m >= n) idx = get_idx(m, x, y, m - n);
        else idx = get_idx(n, y, x, n - m);

        if (idx != -1) {
            if (m >= n) answer = n * idx + y;
            else answer = m * idx + x;
        }

        if (!answer) cout << -1 << '\n';
        else cout << answer << '\n';
    }
}