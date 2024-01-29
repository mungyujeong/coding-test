#include <iostream>
#include <climits>

using namespace std;

int n, d[100'000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> d[i];
    
    int answer = d[0];
    for (int i = 1; i < n; i++) {
        d[i] = max(d[i], d[i] + d[i - 1]);
        answer = max(answer, d[i]);
    }
    cout << answer;
}