#include <iostream>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int tmp = 2;
    for (int i = 0; i < n; i++)
        tmp = 2 * tmp - 1;
    cout << tmp * tmp;
}