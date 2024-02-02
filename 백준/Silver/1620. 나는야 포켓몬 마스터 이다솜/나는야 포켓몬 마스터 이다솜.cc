#include <iostream>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<string, string> dict;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string name;
        cin >> name;
        dict[name] = to_string(i);
        dict[to_string(i)] = name;
    }

    for (int i = 0; i < m; i++) {
        string input;
        cin >> input;
        cout << dict[input] << '\n';
    }
}