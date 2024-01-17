#include <iostream>
#include <algorithm>
#include <unordered_map>

#define MAX_N 500'000

using namespace std;

int n, m;
int arr[MAX_N];
unordered_map<int, int> mapping;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    
    sort(arr, arr + n);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cout << upper_bound(arr, arr + n, x) - lower_bound(arr, arr + n, x) << ' ';
    }
}