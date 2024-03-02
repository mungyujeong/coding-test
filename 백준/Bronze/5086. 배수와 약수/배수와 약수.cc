#include <iostream>

using namespace std;

int a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;
        if (b == (b / a * a)) cout << "factor\n";
        else if (a == (a / b * b)) cout << "multiple\n";
        else cout << "neither\n";
    }
}