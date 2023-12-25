#include <iostream>
#include <string>
#include <list>

using namespace std;

string str;
int m;
list<char> l;

int main(void) {
    cin >> str;

    for (auto i : str)
        l.push_back(i);

    auto cursor = l.end();

    cin >> m;

    for (int i = 0; i < m; i++) {
        char c;
        cin >> c;
        if (c == 'L') {
            if (cursor != l.begin()) {
                cursor--;
            }
        } else if (c == 'D') {
            if (cursor != l.end()) {
                cursor++;
            }
        } else if (c == 'B') {
            if (cursor != l.begin()) {
                cursor--;
                cursor = l.erase(cursor);
                // l.erase(cursor);
            }
        } else if (c == 'P') {
            char input;
            cin >> input;
            l.insert(cursor, input);
        }
    }

    for (auto i : l)
        cout << i;
}