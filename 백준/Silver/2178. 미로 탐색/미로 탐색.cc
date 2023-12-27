#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, result(0);
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

int bfs(int x, int y, vector<vector<int>> graph)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (auto i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= n || ny >= m || nx < 0 || ny < 0) continue;
            if (graph[nx][ny] == 0) continue;
            if (graph[nx][ny] == 1) {
                graph[nx][ny] = graph[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return graph[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m));
    for (auto& row : graph)
        for (auto& element : row)
            scanf("%1d", &element);

    cout << bfs(0, 0, graph) << endl;
}