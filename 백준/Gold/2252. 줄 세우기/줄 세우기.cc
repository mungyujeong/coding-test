#include <iostream>
#include <queue>
#include <vector>

#define MAX_N 32'001

using namespace std;

int n, m, topology[MAX_N];
vector<int> adj[MAX_N];
queue<int> Q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        topology[b]++;
    }

    for (int i = 1; i <= n; i++)
        if (topology[i] == 0)
            Q.push(i);
    
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        cout << cur << ' ';
        for (auto nxt : adj[cur]) {
            topology[nxt]--;
            if (topology[nxt] == 0)
                Q.push(nxt);
        }
    }
}