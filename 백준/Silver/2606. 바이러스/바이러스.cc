#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

#define MAX_N 100

using namespace std;

int n, p;
int visited[MAX_N + 1];
queue<int> Q;
vector<pair<int, int>> v;
vector<int> map[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> p;
    for (int i = 0; i < p; i++) {
        int x, y;
        cin >> x >> y;
        map[x].push_back(y);
        map[y].push_back(x);
        if (x == 1) visited[y] = 1;
        else if (y == 1) visited[x] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            for (auto m : map[i]) {
                visited[m] = 1;
                Q.push(m);
            }
        }
        
        while (!Q.empty()) {
            int x;
            x = Q.front(); Q.pop();
            for (auto m : map[x]) {
                if (!visited[m]) {
                    Q.push(m);
                    visited[m] = 1;
                }
            }
        }
    }

    int answer = 0;

    for (int i = 1; i <= n; i++)
        if (visited[i])
            answer++;

    if (answer == 0) cout << 0;
    else cout << answer - 1;
}