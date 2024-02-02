#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

int n;
unordered_set<string> worker;
string name, record;
vector<string> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name >> record;
        if (record == "enter") worker.insert(name);
        else worker.erase(name);
    }

    for (auto i : worker)
        v.push_back(i);
    sort(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 0; i--)
        cout << v[i] << '\n';
}