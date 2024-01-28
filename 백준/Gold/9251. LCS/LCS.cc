#include <iostream>

#define MAX_N 1'000

using namespace std;

string a, b;
int board[MAX_N + 1][MAX_N + 1];
int answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a;
    cin >> b;

    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1])
                board[i][j] = board[i - 1][j - 1] + 1;
            else 
                board[i][j] = max(board[i - 1][j], board[i][j - 1]);
            
            answer = max(answer, board[i][j]);
        }
    }

    cout << answer;
}