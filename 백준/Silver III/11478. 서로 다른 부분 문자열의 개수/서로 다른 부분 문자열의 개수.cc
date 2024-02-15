#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

string input;
unordered_set<string> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> input;
    for (int i = 0; i < input.size(); i++) {
        for (int j = 1; j <= input.size(); j++) {
            s.insert(input.substr(i, j));
        }
    }
    cout << s.size();
}