#include <iostream>
#include <algorithm>

#define MAX_N 10000

using namespace std;

int n;
int arr[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr[x]++;
    }

    for (int i = 0; i <= MAX_N; i++) 
        while (arr[i]--)
            cout << i << '\n';
}