#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

#define MAX_N 1001

using namespace std;

int n, m, dist[MAX_N], st, en;
vector<pair<int, int>> dijkstra[MAX_N];
int path[MAX_N];
priority_queue<pair<int, int>, 
                vector<pair<int, int>>,
                greater<pair<int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        dijkstra[u].push_back({cost, v});
    }

    cin >> st >> en;

    fill(dist, dist + n + 1, INT_MAX);

    dist[st] = 0;
    pq.push({dist[st], st});
    while (!pq.empty()) {
        int cur_d, cur;
        tie(cur_d, cur) = pq.top(); pq.pop();
        if (cur_d != dist[cur]) continue;
        for (auto i : dijkstra[cur]) {
            int nxt_d, nxt;
            tie(nxt_d, nxt) = i;
            if (dist[nxt] <= dist[cur] + nxt_d) continue;
            dist[nxt] = dist[cur] + nxt_d;
            pq.push({dist[nxt], nxt});
            path[nxt] = cur;
        }
    }

    cout << dist[en] << '\n';
    vector<int> result;
    int cur = en;
    while (cur != st) {
        result.push_back(cur);
        cur = path[cur];
    }
    result.push_back(st);
    cout << result.size() << '\n';
    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << ' ';
}