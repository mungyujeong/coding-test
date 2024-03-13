#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

#define MAX_N 4
#define TAG 100

using namespace std;

int p, d, board[MAX_N][MAX_N], answer, cnt;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
tuple<int, int, int> pos[17];
tuple<int, int, int> tag;

bool in_range(int x, int y) {
    return 0 <= x && x < 4 && 0 <= y && y < 4;
}

void Move() {
    for (int num = 1; num <= 16; num++) {
        int x, y, d;
        tie(x, y, d) = pos[num];
        if (x == -1) continue; // 먹힘
        
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!in_range(nx, ny) || board[nx][ny] == TAG) {
                d = (d + 1) % 8;
                continue;
            }

            // 이동 가능
            int tx, ty, td;
            int nxt = board[nx][ny];
            tie(ignore, ignore, td) = pos[nxt];
            pos[nxt] = make_tuple(x, y, td);
            pos[num] = make_tuple(nx, ny, d);
            board[nx][ny] = num;
            board[x][y] = nxt;
            break;
        }
    }
}

void Backtracking() {
    Move();

    int x, y, d, nd;
    tie(x, y, d) = tag;
    int tmp_board[MAX_N][MAX_N];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            tmp_board[i][j] = board[i][j];
    tuple<int, int, int> tmp_pos[17], tmp_tag;
    for (int i = 0; i < 17; i++)
        tmp_pos[i] = pos[i];
    tmp_tag = tag;
    int tmp_cnt = cnt;

    int nx, ny;
    nx = x; ny = y;
    for (int i = 0; i < 4; i++) {
        nx += dx[d];
        ny += dy[d];
        if (!in_range(nx, ny)) break;
        if (board[nx][ny] == 0) continue;

        tie (ignore, ignore, nd) = pos[board[nx][ny]];
        tag = make_tuple(nx, ny, nd);
        pos[board[nx][ny]] = make_tuple(-1, -1, -1);
        cnt += board[nx][ny];
        board[nx][ny] = TAG;
        board[x][y] = 0;

        Backtracking();

        tag = tmp_tag;
        for (int t = 0; t < 4; t++)
            for (int l = 0; l < 4; l++)
                board[t][l] = tmp_board[t][l];
        for (int t = 0; t < 17; t++)
            pos[t] = tmp_pos[t];
        cnt = tmp_cnt;
    }

    answer = max(answer, cnt);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> p >> d;
            board[i][j] = p;
            pos[p] = make_tuple(i, j, d - 1);
        }
    }

    answer += board[0][0];
    tie(ignore, ignore, d) = pos[board[0][0]];
    tag = make_tuple(0, 0, d);
    pos[board[0][0]] = make_tuple(-1, -1, -1);
    board[0][0] = TAG;
    cnt = answer;
    Backtracking();

    cout << answer;
    return 0;
}