#include <iostream>

#define MAX_N 1000000

using namespace std;

int n;
int arr[MAX_N + 1];
int minus_arr[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x < 0) minus_arr[-x]++;
        else arr[x]++;
    }

    for (int i = MAX_N; i >= 1; i--) {
        if (minus_arr[i] > 0) {
            while (minus_arr[i]) {
                cout << -i << '\n';
                minus_arr[i]--;
            }
        }
    }

    for (int i = 0; i <= MAX_N; i++) {
        if (arr[i] > 0) {
            while (arr[i]) {
                cout << i << '\n';
                arr[i]--;
            }
        }
    }
}