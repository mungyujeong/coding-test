#include <iostream>
#include <algorithm>

#define MAX_N 500'000

using namespace std;
using ll = long long;

ll n, m, x, arr[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    sort(arr, arr + n);
    
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        cout << binary_search(arr, arr + n, x) << ' ';
    }
}