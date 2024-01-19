#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>

#define MAX_N 10

using namespace std; 

int n, m, k, answer;
int add[MAX_N][MAX_N];
int energy[MAX_N][MAX_N] = {5, };
deque<int> board[MAX_N][MAX_N];
queue<int> dead[MAX_N][MAX_N];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void spring() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j].size() == 0) continue;
            int die_energy = 0;
            vector<int> tmp;
            // spring
            for (int t = 0; t < board[i][j].size(); t++) {
                if (energy[i][j] < board[i][j][t]) {
                    die_energy += board[i][j][t] / 2;
                    // dead[i][j].push(board[i][j][t]);
                    // board[i][j].erase(board[i][j].begin() + t--);
                    answer--;
                }
                else {
                    energy[i][j] -= board[i][j][t]++;
                    tmp.push_back(board[i][j][t]);
                }
            }

            board[i][j].clear();
            // summer
            for (int t = 0; t < tmp.size(); t++) {
                board[i][j].push_back(tmp[t]);
            }
            energy[i][j] += die_energy;
            // int idx = 0;
            // while (!dead[i][j].empty()) {
            //     energy[i][j] += dead[i][j].front() / 2;
            //     dead[i][j].pop();
            // }
        }
    }
}

void summer() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // winter
            energy[i][j] += add[i][j]; 

            // fall
            int sz = board[i][j].size();
            if (sz == 0) continue;
            for (int t = 0; t < sz; t++) {
                if (board[i][j][t] % 5 == 0) {
                    for (int d = 0; d < 8; d++) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        board[nx][ny].push_front(1);
                        answer++;
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    answer = m;

    for (int i = 0; i < n; i++) {
        fill(energy[i], energy[i] + n, 5);
        for (int j = 0; j < n; j++)
            cin >> add[i][j];
    }
    
    int x, y, z;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        board[x - 1][y - 1].push_back(z);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sort(board[i][j].begin(), board[i][j].end());

    while (k--) {
        spring();
        summer();
    }

    cout << answer;
}