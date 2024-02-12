#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v, e, a, b, cost, result{0};
vector<pair<int, pair<int, int>>> edges;
int parent[10001];

int findParent(int x)
{
    if (x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main()
{
    cin >> v >> e;
    for (auto i = 1; i <= v; i++) {
        parent[i] = i;
    }
    for (auto i = 0; i < e; i++) {
        cin >> a >> b >> cost;
        edges.push_back({cost, {a, b}});
    }

    sort(edges.begin(), edges.end());

    for (auto& i : edges) {
        cost = i.first;
        a = i.second.first;
        b = i.second.second;
        if (findParent(a) != findParent(b)) {
            unionParent(a, b);
            result += cost;
        }
    }
    cout << result << endl;
}