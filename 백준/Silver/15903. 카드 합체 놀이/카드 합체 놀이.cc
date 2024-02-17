#include <iostream>
#include <algorithm>
#include <queue>

#define MAX_N 1'000

using namespace std;
using ll = long long;

ll n, m, answer;
priority_queue<ll> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        pq.push(-x);
    }

    while(m--) {
        ll a, b;
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        pq.push(a + b);
        pq.push(a + b);
    }

    for (int i = 0; i < n; i++) {
        answer += -pq.top();
        pq.pop();
    }
    cout << answer;
}