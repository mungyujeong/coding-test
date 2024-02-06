#include <iostream>
#include <algorithm>
#include <set>

#define MAX_N 300'000

using namespace std;
using ll = long long;

int n, k;
pair<int, int> jewel[MAX_N];
multiset<int> bag;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) 
        cin >> jewel[i].second >> jewel[i].first;
    
    sort(jewel, jewel + n); // {v, m} 오름차순 정렬

    // 가방 무게
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        bag.insert(c);
    }

    ll answer = 0;

    for (int i = n - 1; i >= 0; i--) {
        int v, m;
        tie(v, m) = jewel[i];
        multiset<int>::iterator it = bag.lower_bound(m);
        if (it == bag.end()) continue;
        answer += v;
        bag.erase(it);
    }

    cout << answer;
}