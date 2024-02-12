#include <iostream>
#include <vector>

#define MAX_N 100

using namespace std;

int n, m, floyd[MAX_N + 1][MAX_N + 1], nxt[MAX_N + 1][MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        fill(floyd[i], floyd[i] + n + 1, 0x3f3f3f3f);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        floyd[a][b] = min(floyd[a][b], c);
        nxt[a][b] = b;
    }

    for (int i = 1; i <= n; i++)
        floyd[i][i] = 0;

    for (int k = 1; k <= n; k++) 
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++) {
                if (floyd[i][k] + floyd[k][j] < floyd[i][j]) {
                    floyd[i][j] = min(floyd[i][k] + floyd[k][j], floyd[i][j]);
                    nxt[i][j] = nxt[i][k];
                }
            }
            
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (floyd[i][j] == 0x3f3f3f3f) cout << "0 ";
            else cout << floyd[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (floyd[i][j] == 0 || floyd[i][j] == 0x3f3f3f3f) {
                cout << "0\n";
                continue;
            }
            vector<int> path;
            int st = i;
            while (st != j) {
                path.push_back(st);
                st = nxt[st][j];
            }
            path.push_back(j);
            cout << path.size() << ' ';
            for (auto p : path) 
                cout << p << ' ';
            cout << '\n';
        }
    }
}