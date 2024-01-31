#include <iostream>
#include <algorithm>

#define MAX_N 1'000

using namespace std;

int n, k, score[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> score[i];

    sort(score, score + n, greater<int>());

    cout << score[k - 1];
}