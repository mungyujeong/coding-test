#include <iostream>
#include <algorithm>

#define MAX_N 1'000

using namespace std;

int n;
int arr[MAX_N][3];
int d[MAX_N][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    
    d[0][0] = arr[0][0];
    d[0][1] = arr[0][1];
    d[0][2] = arr[0][2];

    for (int i = 1; i < n; i++) {
        d[i][0] = min(d[i - 1][1], d[i - 1][2]) + arr[i][0];
        d[i][1] = min(d[i - 1][0], d[i - 1][2]) + arr[i][1];
        d[i][2] = min(d[i - 1][0], d[i - 1][1]) + arr[i][2];
    }

    cout << *min_element(d[n - 1], d[n - 1] + 3);
}