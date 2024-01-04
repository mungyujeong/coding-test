#include <iostream>
#include <queue>

#define MAX_N 100000

using namespace std;

int n, k;
int arr[2 * MAX_N + 1];
int visited[2 * MAX_N + 1];
queue<int> Q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    Q.push(n);
    visited[n] = 1;
    while (!Q.empty()) {
        int x;
        x = Q.front(); Q.pop();
        for (auto i : {x - 1, x + 1, 2 * x}) {
            if (0 <= i && i <= MAX_N) {
                if (i == n) continue;
                if (i != 2 * x) {
                    if (!arr[i] && !visited[i]) {
                        arr[i] = arr[x] + 1;
                        Q.push(i);
                        visited[i] = 1;
                    }
                    else if (arr[i] > arr[x] + 1) {
                        arr[i] = arr[x] + 1;
                        Q.push(i);
                        visited[i] = 1;
                    }
                } 
                else if (i == 2 * x) {
                    if (!arr[i] && !visited[i]) {
                        arr[i] = arr[x];
                        Q.push(i);
                        visited[i] = 1;
                    }
                    else if (arr[i] > arr[x]) {
                        arr[i] = arr[x];
                        Q.push(i);
                        visited[i] = 1;
                    }
                }
            }
        }
    }
    if (n == k) cout << 0;
    else cout << arr[k];
}