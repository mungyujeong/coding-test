#include <iostream>

#define MAX_N 101

using namespace std;

int arr[6];
int white[6] = {1, 1, 2, 2, 2, 8};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
        cout << white[i] - arr[i] << ' ';
    }
}