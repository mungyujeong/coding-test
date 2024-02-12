#include <iostream>
#include <queue>

#define MAX_N 10'001

using namespace std;

int n, work[MAX_N], deg[MAX_N], dp[MAX_N], answer;
vector<int> topology[MAX_N];
queue<int> Q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> work[i] >> x;
        for (int j = 0; j < x; j++) {
            int a;
            cin >> a;
            deg[i]++;
            topology[a].push_back(i);
        } 
    }

    for (int i = 1; i <= n; i++)
        if (deg[i] == 0) {
            Q.push(i);
            dp[i] = work[i];
        }
    
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for (auto nxt : topology[cur]) {
            deg[nxt]--;
            dp[nxt] = max(dp[nxt], work[nxt] + dp[cur]);
            if (deg[nxt] == 0) 
                Q.push(nxt);
        }
    }
    
    for (int i = 1; i <= n; i++)
        answer = max(answer, dp[i]);
    cout << answer;
}