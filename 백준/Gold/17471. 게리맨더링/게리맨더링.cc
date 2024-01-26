#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
#include <climits>

#define MAX_N 10

using namespace std;

int n, answer = INT_MAX;
int population[MAX_N];
vector<int> board[MAX_N];
int board_size[MAX_N];

bool IsValidTeam(const vector<int>& team, const vector<int>& colors) {
    int color = colors[team[0]];
    queue<int> Q;
    Q.push(team[0]);
    int visited[MAX_N] = {};
    visited[team[0]] = 1;

    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        for (int i = 0; i < board_size[x]; i++) {
            if (colors[board[x][i]] != color) continue;
            if (visited[board[x][i]]) continue;
            Q.push(board[x][i]);
            visited[board[x][i]] = 1;
        }
    }

    for (auto i : team)
        if (!visited[i]) return false;
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> population[i];
    
    for (int i = 0; i < n; i++) {
        cin >> board_size[i];
        for (int j = 0; j < board_size[i]; j++) {
            int y;
            cin >> y;
            board[i].push_back(y - 1);
        }
    }

    for (int k = 1; k <= n / 2; k++) {
        vector<int> comb(n, 0);
        fill(comb.end() - k, comb.end(), 1); // k구역 선택

        do { // k개 조합
            vector<int> team1;
            vector<int> team2;
            vector<int> comb2(n, 0);

            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (comb[i]) team1.push_back(i);
                else {
                    team2.push_back(i);
                    comb2[i] = 1;
                }
            }

            if (IsValidTeam(team1, comb) && IsValidTeam(team2, comb2)) { // 만약 두 팀이 각각 연결되어 있으면 전체 합에서 선택된 구간의 인구수만 빼기
                for (int t = 0; t < n; t++) {
                    if (comb[t]) sum += population[t];
                    else sum -= population[t];
                }
                
                answer = min(answer, abs(sum));    
            }
        } while (next_permutation(comb.begin(), comb.end()));

    }
    if (answer == INT_MAX) cout << -1;
    else cout << answer;
}