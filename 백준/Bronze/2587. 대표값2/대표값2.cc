#include <iostream>
#include <algorithm>

using namespace std;

int arr[5];

int main() {
    int t = 5, avg = 0;
    while(t--) {
        cin >> arr[t];
        avg += arr[t];
    }
    sort(arr, arr + 5);
    cout << avg / 5 << "\n";
    cout << arr[5 / 2];

    return 0;
}