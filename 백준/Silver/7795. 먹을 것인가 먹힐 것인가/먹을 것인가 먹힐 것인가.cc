#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 20'000

using namespace std;

int n, m, test_case;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test_case;
    while (test_case--) {
        cin >> n >> m;
        int cnt = 0;
        vector<int> a(n);
        vector<int> b(m);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        sort(b.begin(), b.end());

        for (int i = 0; i < a.size(); i++) {
            int st = 0;
            int mid = 0;
            int en = b.size();
            int target = a[i];
            while (st < en) {
                mid = (st + en) / 2;
                if (target > b[mid]) st = mid + 1;
                else en = mid;
            }
            cnt += en;
        }
        cout << cnt << '\n';
    }
}