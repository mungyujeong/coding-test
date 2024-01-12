#include <iostream>
#include <algorithm>
#include <tuple>

#define MAX_N 100'000

using namespace std;

int n;
pair<int, int> arr[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> arr[i].first >> arr[i].second;
    
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }
}