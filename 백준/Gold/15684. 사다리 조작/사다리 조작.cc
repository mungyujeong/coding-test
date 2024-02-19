#include <iostream>
#include <vector>

#define MAX_N 32

using namespace std;

int n, m, h, ladder[MAX_N][MAX_N], answer = 100;
vector<pair<int, int>> v;

bool check() {
  for (int j = 1; j <= n; j++) {
    int cur = j;
    for (int i = 1; i <= h; i++) {
      if (ladder[i][cur - 1]) cur--;
      else if (ladder[i][cur]) cur++;
    }
    if (cur != j) return false;
  }
  return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = 1;
    }

    if (check()) {
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j < n; j++) {
            if (ladder[i][j - 1] || ladder[i][j] || ladder[i][j + 1]) continue;
            v.push_back({i, j});
        }
    }

    for (int i = 0; i < v.size(); i++) {
        ladder[v[i].first][v[i].second] = 1;
        if (check()) answer = min(answer, 1);

        for (int j = i + 1; j < v.size(); j++) {
            ladder[v[j].first][v[j].second] = 1;
            if (check()) answer = min(answer, 2);

            for (int k = j + 1; k < v.size(); k++) {
                ladder[v[k].first][v[k].second] = 1;
                if (check()) answer = min(answer, 3);
                ladder[v[k].first][v[k].second] = 0;
            }

            ladder[v[j].first][v[j].second] = 0;
        }

        ladder[v[i].first][v[i].second] = 0;
    }

    if (answer == 100) cout << -1;
    else cout << answer;
}