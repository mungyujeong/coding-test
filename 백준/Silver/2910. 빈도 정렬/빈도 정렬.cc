#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

#define MAX_N 1000
#define MAX_C 1'000'000'000

using namespace std;

int n, c;
unordered_map<int, int> m;
unordered_map<int, int> order;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return order[a.second] < order[b.second];
    
    return a.first > b.first;
}

int main() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m[x]++;
        if (order[x] == 0) 
            order[x] = i + 1;
    }

    unordered_map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) 
        v.push_back({it->second, it->first});
    
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++) 
        while (v[i].first--)
            cout << v[i].second << ' ';    
}