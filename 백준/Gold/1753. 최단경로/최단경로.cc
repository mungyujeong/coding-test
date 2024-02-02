#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <tuple>

#define MAX_V 20'001

using namespace std;

int v, e, st, d[MAX_V];
vector<pair<int, int>> graph[MAX_V];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e >> st;
    fill(d, d + v + 1, INT_MAX);

    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }

    priority_queue<pair<int, int>, 
                    vector<pair<int, int>>, 
                    greater<pair<int, int>>> pq;
    
    d[st] = 0;
    // 우선순위 큐에 (0, 시작점) 추가
    pq.push({d[st], st});

    while (!pq.empty()) {
        int cur, dist;
        tie(dist, cur) = pq.top(); pq.pop(); // {비용, 정점 번호}

        // 거리가 d에 있는 값과 다를 경우 넘어감 why? 이미 최단거리로 갱신됐기 때문
        if (d[cur] != dist) continue;

        for (auto nxt : graph[cur]) {
            // 현재 정점과 연결된 정점들의 {비용, 정점 번호}
            int nxt_cur, nxt_dist;
            tie(nxt_dist, nxt_cur) = nxt;

            // 현재 정점에서 다음 정점까지 가는 비용을 더한 값과
            // 원래 있던 다음 정점의 비용값 비교
            // 만약 처음이면 INT_MAX 값이므로 무조건 큼
            if (d[nxt_cur] <= d[cur] + nxt_dist) continue;

            // 현재 노드를 거쳐가는 것이 더 작은 값일 경우
            // 다음 노드의 비용을 갱신하고 우선순위 큐에 추가
            d[nxt_cur] = d[cur] + nxt_dist;
            pq.push({d[nxt_cur], nxt_cur});
        }
    }

    for (int i = 1; i <= v; i++) {
        if (d[i] == INT_MAX) cout << "INF\n";
        else cout << d[i] << '\n';
    }
}