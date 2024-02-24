#include <iostream>
#include <climits>

using namespace std;

int n, m;
int adj[101][101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n ; i++)
        fill(adj[i], adj[i] + n + 1, 0x3f3f3f3f3f);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = adj[b][a] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    int answer;
    int min_val = INT_MAX;
    bool same = false;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) 
            if (i != j)
                cnt += adj[i][j];

        if (cnt < min_val) {
            answer = i;
            min_val = cnt;
            same = false;
        }
        else if (cnt == min_val) {
            same = true;
        }
    }

    cout << answer;
}