#include <iostream>
#include <algorithm>

#define MAX_N 8

using namespace std;

int n, m;
int is_used[MAX_N];
int arr[MAX_N];
int input[MAX_N];

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

    for (int i = 0; i < n; i++) {
        if (!is_used[i]) {
            arr[k] = input[i];
            is_used[i] = 1;
            backtracking(k + 1);
            is_used[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> input[i];
    sort(input, input + n);
    backtracking(0);
}