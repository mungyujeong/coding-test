#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

#define MAX_N 100000

using namespace std;

int n, k;
queue<int> Q;
int arr[MAX_N + 1];
int route[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    if (n >= k) {
        cout << n - k << '\n';
        for (int i = n; i >= k; i--)
            cout << i << ' ';
        return 0;
    }

    fill(arr, arr + MAX_N + 1, -1);
    Q.push(n);
    arr[n] = 0;
    route[n] = n;
    
    while (!Q.empty()) {
        int x;
        x= Q.front(); Q.pop();
        if (x == k) break;
        for (int i : {x - 1, x + 1, 2 * x}) {
            if (i < 0 || i > MAX_N) continue;
            if (arr[i] == -1) {
                arr[i] = arr[x] + 1;
                Q.push(i);
                route[i] = x;
            }
        }
    }

    int length = arr[k];
    cout << length << '\n';
    vector<int> v;
    v.push_back(k);
    for (int i = 0; i < length; i++) {
        v.push_back(route[k]);
        k = route[k];
    }
    for (int i = v.size() - 1; i >= 0; i--)
        cout << v[i] << ' ';
}