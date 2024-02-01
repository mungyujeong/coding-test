#include <iostream>
#include <climits>

#define MAX_N 100'000

using namespace std;
using ll = long long;

ll n, s, arr[MAX_N + 1], answer = INT_MAX;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    ll en = 1;
    ll sum = arr[1];
    for (ll st = 1; st <= n; st++) {
        while (en <= n && sum < s) {
            en++;
            if (en <= n) sum += arr[en];
        }
        if (en > n) break;
        answer = min(answer, en - st + 1);
        sum -= arr[st];
    }

    if (answer == INT_MAX) answer = 0;
    cout << answer;
}