#include <iostream>
#include <algorithm>

#define MAX_N 7

using namespace std;

int n, m;
int arr[MAX_N];
int result[MAX_N];

void backtracking(int curr) {
    if (curr == m) {
        for (int i = 0; i < m; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        result[curr] = arr[i];
        backtracking(curr + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    backtracking(0);
}