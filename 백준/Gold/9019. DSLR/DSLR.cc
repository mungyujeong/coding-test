#include <iostream>
#include <climits>
#include <tuple>
#include <queue>

using namespace std;

int test_case, a, b;

string bfs(int result, string cmd) {
    queue<pair<int, string>> Q;
    int visited[10001] = {};

    Q.push({result, cmd});
    visited[result] = 1;

    while (!Q.empty()) {
        tie(result, cmd) = Q.front(); Q.pop();
        int n = result;

        if (result == b) 
            return cmd;

        for (auto i : {'D', 'S', 'L', 'R'}) {
            result = n;
            if (i == 'D') result = (2 * n) % 10000;
            else if (i == 'S') n == 0 ? result = 9999 : result -= 1;
            else if (i == 'L') result = (n % 1000) * 10 + (n / 1000);
            else result = n / 10 + (n % 10) * 1000;
            if (visited[result]) continue;

            visited[result] = 1;
            Q.push({result, cmd + i});
        }
    }

    return cmd;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> test_case;
    while (test_case--) {
        cin >> a >> b;

        cout << bfs(a, "") << '\n';
    }
}