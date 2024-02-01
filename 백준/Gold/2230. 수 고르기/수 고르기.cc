#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_N 100'000

using namespace std;
using ll = long long;

ll n, m, arr[MAX_N + 1], answer = INT_MAX;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int st = 1;
    int en = 1;

    while (st <= n && en <= n) {
        ll diff = arr[en] - arr[st];
        if (diff >= m) {
            st++;
            answer = min(answer, diff);
        }
        else {
            en++;
        }
    }

    cout << answer;
}