#include <iostream>
#include <algorithm>

#define MAX_N 1'000

using namespace std;

int n, arr[MAX_N], answer;

int get_lis_reverse(int st, int en) {
    int LIS[MAX_N] = {};
    LIS[0] = arr[en - 1];
    int len = 1;

    for (int i = en - 1; i >= st; i--) {
        if (arr[i] > LIS[len - 1]) {
            LIS[len++] = arr[i];
            continue;
        }    
        int idx = lower_bound(LIS, LIS + len, arr[i]) - LIS;
        LIS[idx] = arr[i];
    }

    return len;
}

int get_lis(int st, int en) {
    int result = 0;
    int LIS[MAX_N] = {};
    LIS[0] = arr[st];
    int len = 1;

    for (int i = st; i <= en; i++) {
        if (arr[i] > LIS[len - 1]) {
            LIS[len++] = arr[i];
            continue;
        }    
        int idx = lower_bound(LIS, LIS + len, arr[i]) - LIS;
        LIS[idx] = arr[i];
    }

    result += len;
    int tmp = LIS[len - 1];

    // 반대 방향
    int R_LIS[MAX_N] = {};
    R_LIS[0] = arr[n - 1];
    len = 1;

    for (int i = n - 1; i >= en; i--) {
        if (arr[i] > R_LIS[len - 1]) {
            R_LIS[len++] = arr[i];
            continue;
        }    
        int idx = lower_bound(R_LIS, R_LIS + len, arr[i]) - R_LIS;
        R_LIS[idx] = arr[i];
    }
    result += len;

    return result - 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = 0; i < n; i++) {
        int result = 0;
        result += get_lis(0, i);
        answer = max(answer, result);
    }

    cout << answer;
}