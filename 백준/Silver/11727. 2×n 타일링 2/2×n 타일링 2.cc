#include <iostream>

using namespace std;

int n, d[1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[0] = 1;
    d[1] = 3;
    for (int i = 2; i < n; i++)
        d[i] = (d[i - 1] + d[i - 2] * 2) % 10007;
    cout << d[n - 1];
}