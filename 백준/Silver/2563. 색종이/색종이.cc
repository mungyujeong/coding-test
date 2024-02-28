#include <iostream>

#define MAX_N 101

using namespace std;

bool board[MAX_N][MAX_N];
int n, answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        for (int i = x; i < x + 10; i++) 
            for (int j = y; j < y + 10; j++)
                board[i][j] = true;
    }

    for (int i = 1; i <= 100; i++) 
        for (int j = 1; j <= 100; j++)
            if (board[i][j]) 
                answer++;
    
    cout << answer;
}