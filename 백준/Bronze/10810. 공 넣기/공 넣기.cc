#include <iostream>

#define MAX_N 101

using namespace std;

int n, m, arr[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int x = 0; x < m; x++) {
        int i, j, k;
        cin >> i >> j >> k;
        fill(arr + i, arr + j + 1, k);
    }

    for (int i = 1; i <= n; i++)
        cout << arr[i] << ' ';
}