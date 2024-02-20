#include <iostream>
#include <algorithm>

#define MAX_N 101

using namespace std;

int n, m, arr[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        arr[i] = i;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        reverse(arr + a, arr + b + 1);
    }

    for (int i = 1; i <= n; i++)
        cout << arr[i] << ' ';
}