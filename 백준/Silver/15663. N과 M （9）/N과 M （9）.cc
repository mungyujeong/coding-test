#include <iostream>
#include <algorithm>

#define MAX_N 8

using namespace std;

int n, m;
int arr[MAX_N];
int result[MAX_N];
int is_used[MAX_N];

void backtracking(int curr) {
    if (curr == m) {
        for (int i = 0; i < m; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }

    int last = 0;

    for (int i = 0; i < n; i++) {
        if (last == arr[i]) continue;
        if (is_used[i]) continue;
        last = arr[i];
        result[curr] = arr[i];
        is_used[i] = 1;
        backtracking(curr + 1);
        is_used[i] = 0;
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