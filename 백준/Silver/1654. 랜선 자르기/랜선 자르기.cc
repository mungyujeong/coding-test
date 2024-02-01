#include <iostream>
#include <algorithm>

#define MAX_K 10'000

using namespace std;
using ll = unsigned long long;

ll k, n, cable[MAX_K], answer;

ll calc(int length) {
    ll cnt = 0;
    for (int i = 0; i < k; i++) 
        cnt += (cable[i] / length);

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;
    for (int i = 0; i < k; i++)
        cin >> cable[i];
    
    sort(cable, cable + k);

    ll st = 1;
    ll en = cable[k - 1];

    while (st <= en) {
        ll mid = (st + en) / 2;
        ll cnt = calc(mid);
        // cout << mid << ' ' << cnt << endl;
        if (cnt < n) 
            en = mid - 1;
        else if (cnt >= n) {
            st = mid + 1;
            answer = max(answer, mid);
        }
    }

    cout << answer;
}