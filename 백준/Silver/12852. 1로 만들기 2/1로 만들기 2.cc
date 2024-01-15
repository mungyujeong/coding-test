#include <iostream>
#include <vector>

#define MAX_N 1'000'000

using namespace std;

int n;
int d[MAX_N + 1];
int path[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    if (n == 1) {
        cout << 0 << '\n' << 1;
        return 0;
    }

    path[1] = 0;
    for (int i = 2; i <= n; i++) {
        d[i] = d[i - 1] + 1;
        path[i] = i - 1;
        if (i % 3 == 0 && d[i] > d[i / 3] + 1) {
            d[i] = d[i / 3] + 1;
            path[i] = i / 3;
        }
        if (i % 2 == 0 && d[i] > d[i / 2] + 1) {
            d[i] = d[i / 2] + 1;
            path[i] = i / 2;
        }
    }

    cout << d[n] << '\n';
    cout << n << ' ';
    int x = path[n];
    while (x >= 1) {
        cout << x << ' ';
        x = path[x];
    }
}