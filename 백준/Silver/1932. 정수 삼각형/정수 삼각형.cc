#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 500

using namespace std;

int pyramid[MAX_N][MAX_N];
int original[MAX_N][MAX_N];
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < i + 1; j++) {
            cin >> pyramid[i][j];
            original[i][j] = pyramid[i][j];
        }
        
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < i + 1; j++) {
            pyramid[i + 1][j] = max(pyramid[i + 1][j], original[i + 1][j] + pyramid[i][j]);
            pyramid[i + 1][j + 1] = max(pyramid[i + 1][j + 1], original[i + 1][j + 1] + pyramid[i][j]);
        }
    }

    cout << *max_element(pyramid[n - 1], pyramid[n - 1] + n);
}