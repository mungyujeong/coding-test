#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int dist[10], answer;
vector<pair<int, int>> v;
vector<vector<int>> board = {
    {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40},
    {10, 13, 16, 19, 25, 30, 35, 40},
    {20, 22, 24, 25, 30, 35, 40},
    {30, 28, 27, 26, 25, 30, 35, 40}
};

int Simulate() {
    int cnt = 0;
    int pos[] = {0, 0, 0, 0};
    int idx[] = {0, 0, 0, 0};
    bool is_out[] = {false, false, false, false};
    int cur, d;

    for (auto p : v) {
        tie(cur, d) = p;
        if (is_out[cur]) return 0;

        if (idx[cur] == 0 && board[idx[cur]][pos[cur]] == 10) {
            idx[cur] = 1; 
            pos[cur] = 0;
        }
        else if (idx[cur] == 0 && board[idx[cur]][pos[cur]] == 20) {
            idx[cur] = 2; 
            pos[cur] = 0;
        }
        else if (idx[cur] == 0 && board[idx[cur]][pos[cur]] == 30) {
            idx[cur] = 3; 
            pos[cur] = 0;
        }

        pos[cur] += d;
        if (pos[cur] >= board[idx[cur]].size()) {
            is_out[cur] = true;
            continue;
        }

        for (int i = 0; i < 4; i++) {
            if (i == cur || is_out[i]) continue;
            if ((pos[cur] == pos[i]) && 
                (idx[cur] == idx[i])) 
                return 0; // 이미 있음
            
            if (board[idx[i]][pos[i]] == 25 && board[idx[cur]][pos[cur]] == 25 || 
                board[idx[i]][pos[i]] == 30 && board[idx[cur]][pos[cur]] == 30 && idx[i] == idx[cur]||
                board[idx[i]][pos[i]] == 35 && board[idx[cur]][pos[cur]] == 35 ||
                board[idx[i]][pos[i]] == 40 && board[idx[cur]][pos[cur]] == 40) 
                return 0;
        }
        
        cnt += board[idx[cur]][pos[cur]];
    }

    return cnt;
}

void Backtracking(int depth) {
    if (depth == 10) {
        answer = max(answer, Simulate());
        return;
    }

    for (int i = 0; i < 4; i++) {
        v.push_back({i, dist[depth]});
        Backtracking(depth + 1);
        v.pop_back();
    }    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 10; i++)
        cin >> dist[i];

    Backtracking(0);

    cout << answer;
    return 0;
}