#include <iostream>
#include <algorithm>

#define MAX_N 1'000

using namespace std;

int n, arr[MAX_N], answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int LIS[MAX_N] = {};
    int dist[MAX_N];
    fill(dist, dist + n, 1);
    LIS[0] = arr[0];
    int len = 1;
    int d = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > LIS[len - 1]) {
            dist[i] = ++d;
            LIS[len++] = arr[i];
            continue;
        }
        else if (arr[i] == LIS[len - 1])
            dist[i] = d;
        int idx = lower_bound(LIS, LIS + len, arr[i]) - LIS;
        LIS[idx] = arr[i];
    }

    int R_LIS[MAX_N] = {};
    int r_dist[MAX_N] = {};
    fill(r_dist, r_dist + n, 1);
    R_LIS[0] = arr[n - 1];
    len = 1;
    d = 1;

    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > R_LIS[len - 1]) {
            r_dist[i] = ++d;
            R_LIS[len++] = arr[i];
            continue;
        }
        else if (arr[i] == R_LIS[len - 1])
            r_dist[i] = d;
        int idx = lower_bound(R_LIS, R_LIS + len, arr[i]) - R_LIS;
        R_LIS[idx] = arr[i];
    }

    for (int i = 0; i < n; i++) 
        answer = max(answer, dist[i] + r_dist[i]);

    // for (int i = 0; i < n; i++)
    //     cout << dist[i] << ' ';
    // cout << endl;
    // for (int i = 0 ; i< n;i++)
    //     cout << r_dist[i] << ' ';
    // cout << endl;

    cout << answer - 1;
}