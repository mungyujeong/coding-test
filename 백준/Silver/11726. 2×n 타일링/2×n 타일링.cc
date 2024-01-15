#include <iostream>

#define MAX_N 1'000

using namespace std;

int n;
int d[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i <= MAX_N; i++) 
        d[i] = (d[i - 1] + d[i - 2]) % 10007;
    cout << d[n];
}