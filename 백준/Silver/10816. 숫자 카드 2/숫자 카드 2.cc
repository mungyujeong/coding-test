#include <iostream>
#include <algorithm>
#include <unordered_map>

#define MAX_N 500'000

using namespace std;

int n, m;
int arr[MAX_N];
unordered_map<int, int> mapping;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (mapping[x] > 0) mapping[x]++;
        else {
            arr[i] = x;
            mapping[x] = 1;
        }
    }
    sort(arr, arr + n);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (binary_search(arr, arr + n, x)) cout << mapping[x] << ' ';
        else cout << 0 << ' ';
    }
}