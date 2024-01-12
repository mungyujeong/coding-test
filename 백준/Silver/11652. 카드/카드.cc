#include <iostream>
#include <algorithm>

#define MAX_N 100'000

using namespace std;
using ll = long long;

int n;
ll arr[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll x;    
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    
    sort(arr, arr + n);

    int answer = 1;
    int cnt = 1;
    ll curr = arr[0];
    ll max_val = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] == curr) cnt++;
        else {
            if (answer < cnt) {
                max_val = curr;
                answer = cnt;
            }
            curr = arr[i];
            cnt = 1;
        }
    }
    if (cnt > answer) max_val = curr;
    cout << max_val;
}