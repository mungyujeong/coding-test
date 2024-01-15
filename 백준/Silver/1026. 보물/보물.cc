#include <iostream>
#include <algorithm>

#define MAX_N 50

using namespace std;

int n;
int a[MAX_N];
int b[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n, greater<int>());
    int s = 0;
    for (int i = 0; i < n; i++) s += a[i] * b[i];
    cout << s;
}