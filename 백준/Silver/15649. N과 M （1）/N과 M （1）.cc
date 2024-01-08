#include <iostream>

#define MAX_N 8

using namespace std;

bool is_used[MAX_N];
int result[MAX_N];
int n, m;

void print_result() {
    for (int i = 0; i < m; i++)
        cout << result[i] << ' ';
    cout << '\n';
}

void backtracking(int cnt) {
    if (cnt == m) {
        print_result();
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!is_used[i]) {
            result[cnt] = i;
            is_used[i] = true;
            backtracking(cnt + 1);
            is_used[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    backtracking(0);
}