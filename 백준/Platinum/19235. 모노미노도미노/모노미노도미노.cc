#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int score, board[2][6][4], visited[2][6][4];
vector<vector<int>> shape[3] = {
    {{1, 0},
    {0, 0}},
    {{1, 1},
    {0, 0}},
    {{1, 0},
    {1, 0}},
};

bool in_range(int x, int y) {
    return 0 <= x && x < 6 && 0 <= y && y < 4;
}

bool IsPossible(int block, int type, int row, int col) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (shape[type][i][j]) {
                int nx = row + i;
                int ny = col + j;
                if (!in_range(nx, ny) || board[block][nx][ny]) return false;
            }
        }
    }

    return true;
}

void Drop(int block, int type, int row, int col) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (shape[type][i][j]) {
                int nx = row + i;
                int ny = col + j;
                board[block][nx][ny] = (type == 1) ? 2 : 1;
            }
        }
    }
}

bool Completed(int block, int row) {
    for (int col = 0; col < 4; col++)
        if (board[block][row][col] == 0) 
            return false;
    return true;
}

void Special(int block, int row, int col) {
    int idx = row;

    for (int x = row + 1; x < 6; x++) {
        if (board[block][x][col] || board[block][x][col + 1]) break;
        idx = x;
    }

    board[block][row][col] = 0;
    board[block][row][col + 1] = 0;
    board[block][idx][col] = 2;
    board[block][idx][col + 1] = 2;
}

void Normal(int block, int row, int col) {
    int idx = row;

    for (int x = row + 1; x < 6; x++) {
        if (board[block][x][col]) break;
        idx = x;
    }

    board[block][row][col] = 0;
    board[block][idx][col] = 1;
}

void Tetris(int block) {
    for (int row = 4; row >= 0; row--) {
        for (int col = 0; col < 4; col++) {
            if (board[block][row][col] == 2 && col < 3) {
                Special(block, row, col);
                col++;
            }
            else if (board[block][row][col] == 1) Normal(block, row, col);
        }
    }
}

void CheckRow(int block) {
    int row = 5;
    bool changed = false;
    while (row >= 2) {
        if (Completed(block, row)) {
            score++;
            for (int col = 0; col < 4; col++)
                board[block][row][col] = 0;
            changed = true;
        }
        else row--;
    }

    if (changed)
        Tetris(block);
}

void DeleteLast(int block) {
    for (int row = 5; row > 0; row--) {
        for (int col = 0; col < 4; col++) {
            board[block][row][col] = board[block][row - 1][col];
            board[block][row - 1][col] = 0;
        }
    }
}

void LightColor(int block) {
    int cnt = 0;
    for (int row = 0; row < 2; row++) 
        for (int col = 0; col < 4; col++) 
            if (board[block][row][col]) {
                cnt++;
                break;
            }
        
    for (int i = 0; i < cnt; i++)
        DeleteLast(block);
}

void Gravity(int block, int type, int col) {
    for (int row = 0; row < 6; row++)
        if (!IsPossible(block, type, row + 1, col)) {
            Drop(block, type, row, col);
            break;
        }

    CheckRow(block);
    CheckRow(block);
    LightColor(block);
}

void Simulate(int type, int x, int y) {
    Gravity(0, type, y);

    if (type == 0) Gravity(1, 0, 4 - 1 - x);
    else if (type == 1) Gravity(1, 2, 4 - 1 - x);
    else if (type == 2) Gravity(1, 1, 4 - 1 - (x + 1));
}

int Count() {
    int cnt = 0;
    for (int block = 0; block < 2; block++)
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 4; j++)
                if (board[block][i][j])
                    cnt++;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t, x, y;
    cin >> n;
    while (n--) {
        cin >> t >> x >> y;
        Simulate(t - 1, x, y);
    }

    cout << score << '\n' << Count();
}