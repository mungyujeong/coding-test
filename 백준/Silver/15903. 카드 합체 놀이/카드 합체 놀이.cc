#include <iostream>
#include <algorithm>

#define MAX_N 1'000

using namespace std;
using ll = long long;

ll n, m, arr[MAX_N], answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    while(m--) {
        swap(arr[0], *min_element(arr, arr + n));
        swap(arr[1], *min_element(arr + 1, arr + n));
        arr[0] = arr[1] = arr[0] + arr[1];
    }

    for (int i = 0; i < n; i++) 
        answer += arr[i];
    cout << answer;
}