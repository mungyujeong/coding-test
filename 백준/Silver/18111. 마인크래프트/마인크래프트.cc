#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>

#define MAX_N 500

using namespace std;
using ll = long long;

int n, m , b;
int board[MAX_N][MAX_N];

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> b;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    vector<pair<ll, ll>> v;
    for (int h = 0; h <= 256; h++) {
        int clock = 0;
        int blocks = b;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == h) continue;
                else if (board[i][j] > h) {
                    clock += 2 * (board[i][j] - h);
                    blocks += board[i][j] - h;
                }
                else {
                    clock += h - board[i][j];
                    blocks -= (h - board[i][j]);
                }
            }
        }

        if (blocks >= 0) 
            v.push_back({clock, h});
    }

    sort(v.begin(), v.end(), cmp);
    cout << v[0].first << ' ' << v[0].second;
}