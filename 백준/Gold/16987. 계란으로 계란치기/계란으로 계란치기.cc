#include <iostream>

#define MAX_N 8

using namespace std;

int n, answer, cnt;
int s[MAX_N];
int w[MAX_N];

void backtracking(int curr) {
    if (curr == n) {
        answer = max(answer, cnt);
        return;
    }

    if (s[curr] <= 0 || cnt == n - 1)
        backtracking(curr + 1);
    else {
        for (int i = 0; i < n; i++) {
            if (i == curr || s[i] <= 0) continue;

            s[curr] -= w[i];
            s[i] -= w[curr];
            if (s[curr] <= 0) cnt++;
            if (s[i] <= 0) cnt++;
            backtracking(curr + 1);
            if (s[curr] <= 0) cnt--;
            if (s[i] <= 0) cnt--;
            s[curr] += w[i];
            s[i] += w[curr];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> s[i] >> w[i];
    
    backtracking(0);
    cout << answer;
}