#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <tuple>

#define MAX_V 20'001

using namespace std;

int v, e, st, dist[MAX_V];
vector<pair<int, int>> adj[MAX_V];

int main() {
    cin >> v >> e >> st;
    fill(dist, dist + v + 1, INT_MAX);

    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    priority_queue<pair<int, int>, 
                    vector<pair<int, int>>, 
                    greater<pair<int, int>>> pq;
    
    dist[st] = 0;
    pq.push({dist[st], st});
    while (!pq.empty()) {
        int node, edge;
        tie(edge, node) = pq.top(); pq.pop();
        if (dist[node] != edge) continue;
        for (auto nxt : adj[node]) {
            int nxt_node, nxt_edge;
            tie(nxt_edge, nxt_node) = nxt;
            if (dist[nxt_node] <= dist[node] + nxt_edge) continue;
            dist[nxt_node] = dist[node] + nxt_edge;
            pq.push({dist[nxt_node], nxt_node});
        }
    }

    for (int i = 1; i <= v; i++) {
        if (dist[i] == INT_MAX) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}