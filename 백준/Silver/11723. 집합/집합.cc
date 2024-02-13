#include <iostream>

using namespace std;

int m, set[21];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m;
    for (int i = 0; i < m; i++) {
        string cmd;
        int x;
        cin >> cmd;
        if (cmd == "add") {
            cin >> x;
            set[x] = 1;
        }
        else if (cmd == "remove") {
            cin >> x;
            set[x] = 0;
        }
        else if (cmd == "check") {
            cin >> x;
            cout << set[x] << '\n';
        }
        else if (cmd == "toggle") {
            cin >> x;
            (set[x] == 1) ? set[x] = 0 : set[x] = 1;
        }
        else if (cmd == "all") fill (set, set + 21, 1);
        else fill (set, set + 21, 0);
    }
}