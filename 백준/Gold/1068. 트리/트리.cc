#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, root, del_node, answer;
vector<vector<int>> adj(51);
vector<bool> deleted(51, false);

void bfs() {
    queue<int> q;
    deleted[del_node] = true;
    q.push(del_node);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        deleted[cur] = true;
        for (auto nxt : adj[cur]) {
            if (deleted[nxt]) continue;
            deleted[nxt] = true;
            q.push(nxt);
        }
    }
}

bool IsLeaf(int cur) {
    for (auto nxt : adj[cur]) {
        if (deleted[nxt]) continue;
        else return false;
    }
    return true;
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
    bfs();

    for (int i = 0; i < n; i++) {
        if (deleted[i]) continue;
        if (IsLeaf(i)) answer++;
    }

    cout << answer;

    return 0;
}