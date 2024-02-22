#include <iostream>
#include <queue>

#define MAX_N 101

using namespace std;

int n, adj[MAX_N][MAX_N];
vector<int> v[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
            if (adj[i][j]) v[i].push_back(j);
        }
    }

    for (int i = 1; i <= n; i++) {
        int visited[MAX_N] = {};
        queue<int> Q;
        for (auto nxt : v[i]) {
            visited[nxt] = 1;
            Q.push(nxt);
        }

        while (!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            for (auto nxt : v[cur]) {
                if (visited[nxt]) continue;
                visited[nxt] = 1;
                adj[i][nxt] = 1;
                Q.push(nxt);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << adj[i][j] << ' ';
        cout << '\n';
    }
}