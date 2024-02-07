#include <iostream>
#include <queue>
#include <vector>

#define MAX_N 1'001

using namespace std;

int n, m, u, v;
int visited[MAX_N];
vector<int> adj[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        visited[i] = 1;
        answer++;
        queue<int> Q;
        Q.push(i);

        while (!Q.empty()) {
            int cur = Q.front(); Q.pop();
            for (auto nxt : adj[cur]) {
                if (visited[nxt]) continue;
                Q.push(nxt);
                visited[nxt] = 1;
            }
        }
    }

    cout << answer;
}