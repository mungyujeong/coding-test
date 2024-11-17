#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, root, del_node, answer;
vector<vector<int>> adj(51);
vector<bool> deleted(51, false);

int dfs(int cur) {
    if (cur == del_node) return 0;
    if (adj[cur].empty()) return 1;
    if (adj[cur].size() == 1 
        && adj[cur].front() == del_node) return 1;
    
    int cnt = 0;

    for (auto nxt : adj[cur])
        cnt += dfs(nxt);

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (p == -1) root = i;
        else adj[p].push_back(i);
    }

    cin >> del_node;

    cout << dfs(root);

    return 0;
}