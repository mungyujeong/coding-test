#include <iostream>

#define MAX_N 100

using namespace std;

int n, arr[MAX_N], answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    int limit = arr[n - 1] - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > limit) {
            answer += arr[i] - limit;
            limit--;
        }
        else limit = arr[i] - 1;
    }

    cout << answer;
}