#include <iostream>

#define MAX_N 200

using namespace std;

int n, k, board[MAX_N], answer, pos[MAX_N];

void Rotate() {
    int tmp = board[2 * n - 1];
    for (int i = 2 * n - 1; i > 0; i--)
        board[i] = board[i - 1];

    board[0] = tmp;

    for (int i = 2 * n - 1; i > 0; i--)
        pos[i] = pos[i - 1];

    pos[0] = pos[n - 1] = 0;
}

void Move() {
    for (int i = n - 2; i >= 0; i--) {
        if (pos[i]) {
            if (pos[i + 1] || board[i + 1] <= 0) continue;
            if (i + 1 == n - 1) {
                board[n - 1]--;
                pos[i] = 0;
                continue;
            }
            board[i + 1]--;
            pos[i] = 0;
            pos[i + 1] = 1;
        }
    }
}

void Add() {
    if (pos[0] == 0 && board[0] > 0) {
        pos[0] = 1;
        board[0]--;
    }
}

int Check() {
    int cnt = 0;
    for (int i = 0; i < 2 * n; i++)
        if (board[i] <= 0)
            cnt++;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < 2 * n; i++)
        cin >> board[i];

    while (true) {
        answer++;

        Rotate();
        Move();
        Add();

        if (Check() >= k) break;
    }

    cout << answer;
    return 0;
}