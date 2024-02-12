#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAX_N 10'000

using namespace std;

int v, e, answer;
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
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({c, a, b});
    }
    sort(edge.begin(), edge.end());

    for (int i = 0; i < e; i++) {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if (!is_diff_group(a, b)) continue;
        answer += cost;
    }

    cout << answer;
}