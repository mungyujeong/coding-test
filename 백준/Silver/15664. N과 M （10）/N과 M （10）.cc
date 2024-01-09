#include <iostream>
#include <algorithm>

#define MAX_N 8

using namespace std;

int n, m;
int arr[MAX_N];
int result[MAX_N];

void backtracking(int curr, int idx) {
    if (curr == m) {
        for (int i = 0; i < m; i++) 
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }

    int last = 0;
    for (int i = idx; i < n; i++) {
        if (last == arr[i]) continue;
        last = arr[i];
        result[curr] = arr[i];
        backtracking(curr + 1, i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0;i < n; i++)
        cin>> arr[i];
    sort(arr, arr + n);

    backtracking(0, 0);
}