#include <iostream>

using namespace std;

int t, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> c;
        int nxt = c;
        for (auto rest : {25, 10, 5, 1}) {
            nxt = c / rest;
            c %= rest;
            cout << nxt << ' ';
        }
        cout << '\n';
    }
}