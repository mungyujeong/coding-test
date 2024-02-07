#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX_N 1'001

using namespace std;

int n, m, v;
vector<int> adj[MAX_N];
vector<int> result;
int dfs_visited[MAX_N];

void dfs(int cur) {
    cout << cur << ' ';
    dfs_visited[cur] = 1;
    for (auto nxt : adj[cur]) {
        if (dfs_visited[nxt]) continue;
        dfs(nxt);
    }
}

void bfs() {
    queue<int> Q;
    int visited[MAX_N] = {};

    Q.push(v);
    visited[v] = 1;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        cout << cur << ' ';
        for (auto nxt : adj[cur]) {
            if (visited[nxt]) continue;
            visited[nxt] = 1;
            Q.push(nxt);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    dfs(v);
    cout << '\n';
    bfs();
}