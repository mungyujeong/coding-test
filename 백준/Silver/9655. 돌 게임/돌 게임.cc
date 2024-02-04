#include <iostream>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if (n % 2) cout << "SK";
    else cout << "CY";
}