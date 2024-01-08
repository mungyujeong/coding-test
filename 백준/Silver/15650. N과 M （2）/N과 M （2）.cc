#include <iostream>

#define MAX_N 9

using namespace std;

int n, m;
int is_used[MAX_N];
int arr[MAX_N];

void print_comb() {
    for (int i = 0; i < m; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

void backtracking(int k, int start) {
    if (k == m) {
        print_comb();
        return;
    }

    for (int i = start; i <= n; i++) {
        if (!is_used[i]) {
            arr[k] = i;
            is_used[i] = 1;
            backtracking(k + 1, i + 1);
            is_used[i] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    backtracking(0, 1);
}