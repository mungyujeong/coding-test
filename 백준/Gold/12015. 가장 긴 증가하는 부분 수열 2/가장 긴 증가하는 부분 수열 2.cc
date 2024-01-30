#include <iostream>
#include <algorithm>

#define MAX_N 1'000'000

using namespace std;

int n, a[MAX_N], length[MAX_N], LIS[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    LIS[0] = a[0];
    int len = 1;

    for (int i = 0; i < n; i++) {
        if (a[i] > LIS[len - 1]) {
            LIS[len++] = a[i];
            continue;
        }
        int idx = lower_bound(LIS, LIS + len, a[i]) - LIS;
        LIS[idx] = a[i];
    }

    cout << len;
}