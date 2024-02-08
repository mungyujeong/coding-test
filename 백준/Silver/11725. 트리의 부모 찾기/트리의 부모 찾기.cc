#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 100'001

using namespace std;

int n, p[MAX_N];
vector<int> adj[MAX_N];

void bfs() {
    queue<int> Q;
    Q.push(1);
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for (auto nxt : adj[cur]) {
            if (p[nxt]) continue;
            p[nxt] = cur;
            Q.push(nxt);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs();

    for (int i = 2; i <= n; i++)
        cout << p[i] << '\n';
}