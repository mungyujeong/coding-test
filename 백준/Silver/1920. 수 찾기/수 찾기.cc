#include <iostream>
#include <algorithm>

#define MAX_N 100'000

using namespace std;

int n, m;
int arr[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cout << binary_search(arr, arr + n, x) << '\n'; 
    }
}