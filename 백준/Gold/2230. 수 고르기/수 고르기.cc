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
    for (int st = 1; st <= n; st++) {
        while (en <= n && arr[en] - arr[st] < m) en++;
        if (en > n) break;
        answer = min(answer, arr[en] - arr[st]);
    }
    cout << answer;
}