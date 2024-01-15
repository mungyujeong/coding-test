#include <iostream>

#define MAX_N 100'000

using namespace std;

int n, m;
int d[MAX_N + 1];
int arr[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        d[i] = d[i - 1] + arr[i];
    }
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << d[b] - d[a] + arr[a] << '\n';   
    }
}