#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<string, vector<string>> gg;
unordered_map<string, string> team;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string group;
        int num;
        cin >> group;
        cin >> num;
        for (int j = 0; j < num; j++) {
            string name;
            cin >> name;
            gg[group].push_back(name);
            team[name] = group;
        }
    }

    for (int i = 0; i < m; i++) {
        string input;
        int type;
        cin >> input;
        cin >> type;
        if (type == 0) {
            sort(gg[input].begin(), gg[input].end());
            for (auto i : gg[input])
                cout << i << '\n';
        }
        else {
            cout << team[input] << '\n';
        }
    }
}