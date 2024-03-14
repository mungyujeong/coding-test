#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>

#define MAX_N 20
#define X first
#define Y second

using namespace std;

int n, m, c, board[MAX_N][MAX_N];
pair<int, int> car, st[MAX_N * MAX_N], en[MAX_N * MAX_N];
bool arrived[MAX_N * MAX_N] = {false, };
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

tuple<int, int, int, int> BFS(pair<int, int> target, int num) {
    queue<pair<int, int>> Q;
    int visited[MAX_N][MAX_N] = {};

    Q.push(car);
    visited[car.X][car.Y] = 1;

    while (!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front(); Q.pop();
        if (target.X == x && target.Y == y) {
            // cout << visited[x][y] - 1 << ' ' << num << endl;
            return make_tuple(visited[x][y] - 1, x, y, num);
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!in_range(nx, ny)) continue;
            if (board[nx][ny]) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = visited[x][y] + 1;
            Q.push({nx, ny});
        }
    }

    return make_tuple(-1, -1, -1, -1);
}

void Move(int dist, pair<int, int> target) {
    car = target;
    c -= dist;
    // cout << "Moved: " << car.X << ' ' << car.Y << ' ' << c << endl;
}

tuple<int, int, int, int> Select() {
    vector<tuple<int, int, int, int>> selected;
    for (int i = 0; i < m; i++)
        if (!arrived[i]) 
            selected.push_back(BFS(st[i], i));
    
    sort(selected.begin(), selected.end());
    return selected[0];
}

bool Simulate() {
    int dist, num;
    tie(dist, ignore, ignore, num) = Select();

    // 도달 불가능한 고객이 있다면
    if (dist == -1 || c < dist) {
        c = -1;
        return false;
    }
    
    // x, y로 자동차 이동, c 갱신
    Move(dist, st[num]);
    
    // num의 목적지로 이동
    tie(dist, ignore, ignore, num) = BFS(en[num], num);
    if (dist == -1 || c < dist) {
        c = -1;
        return false;
    }

    // 목적지로 이동
    Move(dist, en[num]);
    // c += 이동거리 * 2 
    c += dist * 2;
    arrived[num] = true;

    return true;
}

bool AllArived() {
    for (int i = 0; i < m; i++)
        if (!arrived[i])
            return false;
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    
    int x, y;
    cin >> x >> y;
    car = make_pair(x - 1, y - 1);

    for (int i = 0; i < m; i++) {
        int x_s, y_s, x_e, y_e;
        cin >> x_s >> y_s >> x_e >> y_e;
        st[i] = make_pair(x_s - 1, y_s - 1);
        en[i] = make_pair(x_e - 1, y_e - 1);
    }

    while (true) {
        if (!Simulate()) break;
        if (AllArived()) break;
    }

    cout << c;
}