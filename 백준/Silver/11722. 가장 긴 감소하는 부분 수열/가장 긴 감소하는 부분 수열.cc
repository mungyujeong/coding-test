#include <iostream>
#include <algorithm>

#define MAX_N 1'000

using namespace std;

int n, arr[MAX_N], answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int LIS[MAX_N] = {};
    LIS[0] = arr[n - 1];
    int len = 1;

    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > LIS[len - 1]) {
            LIS[len++] = arr[i];
            continue;
        }    
        int idx = lower_bound(LIS, LIS + len, arr[i]) - LIS;
        LIS[idx] = arr[i];
    }

    cout << len;
}