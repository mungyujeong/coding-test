#include <iostream>
#include <cmath>
#include <algorithm>

#define MAX_N 300'001

using namespace std;

int n, cnt;
int arr[MAX_N];

int main() {
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt += arr[i];
    }
    
    sort(arr, arr + n);

    int limit = floor(n * 0.15 + 0.5);
    for (int i = 0; i < limit; i++) {
        cnt -= arr[i];
        cnt -= arr[n - i - 1];
    }

    double answer = floor((double)cnt / (n - 2 * limit) + 0.5);
    cout << answer;
}