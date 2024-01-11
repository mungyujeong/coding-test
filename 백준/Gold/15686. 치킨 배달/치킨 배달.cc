#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, result{1000000};
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;

int getDistance(vector<pair<int, int>> home, vector<pair<int, int>> chicken) {
    int distance{0};

    for (auto i : home) {
        int minimalDist = 1e9;
        for (auto j : chicken) {
            int dist = abs(i.first - j.first) + abs(i.second - j.second);
            minimalDist = min(minimalDist, dist);
        }
        distance += minimalDist;
    }
    return distance;
}

int main()
{
    cin >> n >> m;
    for (auto i = 0; i < n; i++) {
        for (auto j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x == 2) chicken.push_back({i, j});
            else if (x == 1) home.push_back({i, j});
        }
    }

    vector<int> v(chicken.size(), 0);
    vector<pair<int, int>> selected(m);
    for (auto i = 0; i < m; i++) v[i] = 1;
    
    do {
        selected.clear();
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 1) {
                selected.push_back(chicken[i]);
            }
        }
        
        result = min(result, getDistance(home, selected));
    } while (prev_permutation(v.begin(), v.end()));
    
    cout << result << endl;
}