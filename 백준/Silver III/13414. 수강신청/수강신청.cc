#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int k, l, idx;
string x;
unordered_map<string, int> m;
vector<pair<int, string>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> l;
    for (int i = 0; i < l; i++) {
        cin >> x;
        m[x] = i;
    }

    unordered_map<string, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++) 
        v.push_back({iter->second, iter->first});

    sort(v.begin(), v.end());

    for (int i = 0; i < k; i++) {
        if (v[i].second == "") break;
        cout << v[i].second << '\n';
    }
}