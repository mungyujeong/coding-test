#include <iostream>
#include <algorithm>

#define MAX_N 1000'000

using namespace std;
using ll = long long;

int n;
ll arr[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        int len = x.length();
        for (int j = 0; j < len / 2; j++) 
            swap(x[j], x[len - j - 1]);

        arr[i] = stol(x);
    }

    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}