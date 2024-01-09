#include <iostream>

#define MAX_N 40

using namespace std;

int n, cnt;
int arr_y[MAX_N];
int arr_cl[MAX_N];
int arr_cr[MAX_N];

void backtracking(int x) {
    if (x == n) {
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (arr_y[i] || arr_cr[x + i] || arr_cl[x - i + n - 1]) continue;

        arr_y[i] = 1;
        arr_cr[x + i] = 1;
        arr_cl[x - i + n - 1] = 1;
        backtracking(x + 1);
        arr_y[i] = 0;
        arr_cr[x + i] = 0;
        arr_cl[x - i + n - 1] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    backtracking(0);
    cout << cnt;
}