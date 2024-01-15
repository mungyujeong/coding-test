#include <iostream>

#define MAX_N 300

using namespace std;

int n;
int d[MAX_N + 1][MAX_N + 1];
int score[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> score[i];

    d[1][1] = score[1];
    d[1][2] = 0;
    d[2][1] = score[2];
    d[2][2] = score[1] + score[2];
    for (int i = 3; i <= n; i++) {
        d[i][1] = max(d[i - 2][1], d[i - 2][2]) + score[i];
        d[i][2] = d[i - 1][1] + score[i];
    }
    cout << max(d[n][1], d[n][2]);
}