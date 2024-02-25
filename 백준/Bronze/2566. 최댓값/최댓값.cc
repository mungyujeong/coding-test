#include <iostream>

using namespace std;

int max_val, x, y;
string str;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    x = y = 1;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            int num;
            cin >> num;
            if (max_val < num) {
                max_val = num;
                x = i; y = j;
            }
        }
    }

    cout << max_val << '\n' << x << ' ' << y;
}