#include <iostream>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<string, string> id;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        id[a] = b;
    }
    for (int i = 0; i < m; i++) {
        string a;
        cin >> a;
        cout << id[a] << '\n';
    }
}