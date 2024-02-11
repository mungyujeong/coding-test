#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 32'001

using namespace std;

int n, m, deg[MAX_N];
vector<int> adj[MAX_N];
vector<int> result;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }

    queue<int> Q;
    for (int i = 1; i <= n; i++) 
        if (deg[i] == 0) 
            Q.push(i);
    
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        result.push_back(cur);
        for (auto nxt : adj[cur]) {
            deg[nxt]--;
            if (deg[nxt] == 0) Q.push(nxt);
        }
    }

    for (auto i : result) {
        cout << i << ' ';
    }
}