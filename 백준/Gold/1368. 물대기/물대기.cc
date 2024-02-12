#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAX_N 301

using namespace std;

int n, answer;
vector<tuple<int, int, int>> edge;
vector<int> parent(MAX_N, -1);

int find(int x) {
    if (parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

bool is_diff_group(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (parent[a] == parent[b]) parent[a]--;
    if (parent[a] < parent[b]) parent[b] = a;
    else parent[a] = b;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        int cost;
        cin >> cost;
        edge.push_back({cost, i, n});
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cost;
            cin >> cost;
            if (i >= j) continue;
            edge.push_back({cost, i, j});
        }
    }
    sort(edge.begin(), edge.end());

    for (auto i : edge) {
        int cost, a, b;
        tie(cost, a, b) = i;
        if (!is_diff_group(a, b)) continue;
        answer += cost;
    }

    cout << answer;
}