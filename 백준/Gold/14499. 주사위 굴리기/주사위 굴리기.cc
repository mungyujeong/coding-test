#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

#define MAX_N 20

int n, m, x, y, k, dir;
int board[MAX_N][MAX_N];

// 동 서 북 남
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
deque<int> dice_row(4, 0);
deque<int> dice_col(4, 0);

void move() {
    if (dir == 0) {
        // rotate(dice_row.begin(), dice_row.begin() + 1, dice_row.end());
        dice_row.push_front(dice_row.back());
        dice_row.pop_back();
        dice_col[1] = dice_row[1];
        dice_col[3] = dice_row[3];
    }
    else if (dir == 1) {
        // rotate(dice_row.begin(), dice_row.begin() - 1, dice_row.end());
        dice_row.push_back(dice_row.front());
        dice_row.pop_front();
        dice_col[1] = dice_row[1];
        dice_col[3] = dice_row[3];
    }
    else if (dir == 2) {
        // rotate(dice_col.begin(), dice_col.begin() + 1, dice_col.end());
        dice_col.push_back(dice_col.front());
        dice_col.pop_front();
        dice_row[1] = dice_col[1];
        dice_row[3] = dice_col[3];
    }
    else {
        // rotate(dice_col.begin(), dice_col.begin() - 1, dice_col.end());
        dice_col.push_front(dice_col.back());
        dice_col.pop_back();
        dice_row[1] = dice_col[1];
        dice_row[3] = dice_col[3];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> board[i][j];
        
    while (k--) {
        cin >> dir;
        dir--;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        move();
        if (board[nx][ny] == 0)
            board[nx][ny] = dice_row[3];
        else {
            dice_row[3] = dice_col[3] = board[nx][ny];
            board[nx][ny] = 0;
        } 
        x = nx; y = ny;
        cout << dice_row[1] << '\n';
    }
}