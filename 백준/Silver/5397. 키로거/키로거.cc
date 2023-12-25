#include <iostream>
#include <string>
#include <list>

using namespace std;

int n;
string str;

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        list<char> L = {};

        cin >> str;
        
        auto cur = L.begin();

        for (auto i : str) {
            if (i == '<') {
                if (cur != L.begin()) cur--;
            } else if (i == '>') {
                if (cur != L.end()) cur++;
            } else if (i == '-') {
                if (cur != L.begin()) {
                    cur--;
                    cur = L.erase(cur);
                }
            } else {
                L.insert(cur, i);
            }
        }

        for (auto i : L)
            cout << i;
        cout << "\n";
    }

    return 0;
}