#include <iostream>
#include <algorithm>

#define MAX_N 1000000

using namespace std;

int n;
int arr[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr[i] = x + MAX_N;
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) 
        cout << arr[i] - MAX_N << '\n';
}