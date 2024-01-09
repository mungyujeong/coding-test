#include <iostream>

#define MAX_N 20

using namespace std;

int n, s, cnt;
int arr[MAX_N];

void backtracking(int curr, int sum) {
    if (curr == n) {
        if (s == sum)
            cnt++;
        return;
    }

    backtracking(curr + 1, sum);
    backtracking(curr + 1, sum + arr[curr]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    backtracking(0, 0);
    if (s == 0) cnt--;
    cout << cnt;
}