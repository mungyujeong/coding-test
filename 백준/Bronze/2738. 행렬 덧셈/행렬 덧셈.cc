#include <iostream>

#define MAX_N 100

using namespace std;

int n, m, matrix[MAX_N][MAX_N], x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> x;
                matrix[i][j] += x;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            cout << matrix[i][j] << ' ';
        cout << '\n';
    }
}