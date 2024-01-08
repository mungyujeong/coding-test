#include <iostream>

#define MAX_N 8

using namespace std;

int n, m;
// int is_used[MAX_N];
int arr[MAX_N];

void print_comb() {
    for (int i = 0; i < m; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

void backtracking(int k) {
    if (k == m) {
        print_comb();
        return;
    }

    for (int i = 1; i <= n; i++) {
        arr[k] = i;
        backtracking(k + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    backtracking(0);
}