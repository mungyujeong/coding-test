#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

#define MAX_N 20

using namespace std;

int n, answer = INT_MAX;
int board[MAX_N][MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    
    vector<int> comb(n, 0);
    fill(comb.begin() + n / 2, comb.end(), 1);
    do {
        vector<int> a_team;
        vector<int> b_team;
        for (int i = 0; i < n; i++) {
            if (comb[i]) a_team.push_back(i);
            else b_team.push_back(i);
        }

        int cnt = 0;
        for (int i = 0; i < a_team.size(); i++) 
            for (int j = i + 1; j < a_team.size(); j++) 
                cnt += board[a_team[i]][a_team[j]] + board[a_team[j]][a_team[i]];
            
        for (int i = 0; i < b_team.size(); i++) 
            for (int j = i + 1; j < b_team.size(); j++) 
                cnt -= board[b_team[i]][b_team[j]] + board[b_team[j]][b_team[i]];
         
        answer = min(answer, abs(cnt));
    } while (next_permutation(comb.begin(), comb.end()));    

    cout << answer;
}