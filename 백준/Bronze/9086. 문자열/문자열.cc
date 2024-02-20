#include <iostream>

#define MAX_N 101

using namespace std;

int n;
string str;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> str;
        cout << str.front() << str.back() << '\n';
    }
}