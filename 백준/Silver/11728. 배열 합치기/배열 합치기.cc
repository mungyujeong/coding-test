#include <iostream>
#include <deque>
#include <vector>

#define MAX_N 1000000

using namespace std;

int n, m;
int a[MAX_N];
int b[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int aidx = 0;
    int bidx = 0;
    for (int i = 0; i < m + n; i++) {
        if (aidx == n) cout << b[bidx++] << ' ';
        else if (bidx == m) cout << a[aidx++] << ' ';
        else if (a[aidx] <= b[bidx]) cout << a[aidx++] << ' ';
        else cout << b[bidx++] << ' ';
    }
}