#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 100000

using namespace std;

int n, k;
queue<int> Q;
int visited[2 * MAX_N + 1];
int visit_time[2 * MAX_N + 1];

int main() {
    cin >> n >> k;
    Q.push(n);
    visited[n] = 1;

    if (n == k) {
        cout << 0;
        return 0;
    }
    while (!Q.empty()) {
        int x;
        tie(x) = Q.front();
        Q.pop();
        visited[x] = 1;
        
        int case_1 = x - 1;
        int case_2 = x + 1;
        int case_3 = 2 * x;

        if (case_1 == k || case_2 == k || case_3 == k) {
            cout << visit_time[x] + 1;
            return 0;
        }

        if (0 <= case_1 && case_1 <= MAX_N && !visited[case_1]) {
            visited[case_1] = 1;
            Q.push(case_1);
            visit_time[case_1] = visit_time[x] + 1;
        }
        if (0 <= case_2 && case_2 <= MAX_N && !visited[case_2]) {
            visited[case_2] = 1;
            Q.push(case_2);
            visit_time[case_2] = visit_time[x] + 1;
        }
        if (0 <= case_3 && case_3 <= MAX_N && !visited[case_3]) {
            visited[case_3] = 1;
            Q.push(case_3);
            visit_time[case_3] = visit_time[x] + 1;
        }
    }
}