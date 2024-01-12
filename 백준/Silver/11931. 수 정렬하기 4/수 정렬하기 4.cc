#include <iostream>
#include <algorithm>

#define MAX_N 1000000
#define OFFSET 1000000

using namespace std;

int n;
int arr[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr[i] = x + OFFSET;
    }

    sort(arr, arr + n, greater<int>());

    for (int i = 0; i < n; i++) 
        cout << arr[i] - OFFSET << '\n';
}