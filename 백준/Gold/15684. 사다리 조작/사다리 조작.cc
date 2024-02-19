#include <iostream>
#include <vector>

#define MAX_N 32

using namespace std;

int n, m, h, ladder[MAX_N][MAX_N], answer = 100;

void backtracking(int depth, int cnt) {
    int x = depth / (n - 1);
    int y = depth % (n - 1);

    if (cnt > 3 || answer <= cnt || answer == 0) return;

    if (x == h || cnt == 3) {
        vector<int> v;
        for (int i = 0; i < n; i++)
            v.push_back(i);
        
        for (int i = 0; i < h; i++) 
            for (int j = 0; j < n - 1; j++) 
                if (ladder[i][j]) 
                    swap(v[j], v[j + 1]);

        for (int i = 0; i < n; i++) 
            if (v[i] != i) return;

        answer = min(answer, cnt);
        return;
    }

    backtracking(depth + 1, cnt);
    if (ladder[x][y]) return;
    if (y - 1 >= 0 && ladder[x][y - 1]) return;
    if (y + 1 < n - 1 && ladder[x][y + 1]) return;

    ladder[x][y] = 1;
    backtracking(depth + 1, cnt + 1);
    ladder[x][y] = 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ladder[a - 1][b - 1] = 1;
    }

    backtracking(0, 0);

    if (answer == 100) cout << -1;
    else cout << answer;
}