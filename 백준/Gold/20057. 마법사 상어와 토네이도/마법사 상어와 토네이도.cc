#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 499

using namespace std;

int n, board[MAX_N][MAX_N], answer;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
vector<vector<pair<int, int>>> dir[4] = {
    // d = 0
    {{{-1, 1}, {1, 1}},   // 1%
    {{-2, 0}, {2, 0}},   // 2%
    {{0, -2}},           // 5%
    {{-1, 0}, {1, 0}},   // 7%
    {{-1, -1}, {1, -1}}}, // 10%
    // d = 1
    {{{-1, -1}, {-1, 1}},   // 1%
    {{0, -2}, {0, 2}},   // 2%
    {{2, 0}},           // 5%
    {{0, -1}, {0, 1}},   // 7%
    {{1, -1}, {1, 1}}}, // 10%
    // d = 2
    {{{-1, -1}, {1, -1}},   // 1%
    {{-2, 0}, {2, 0}},   // 2%
    {{0, 2}},           // 5%
    {{-1, 0}, {1, 0}},   // 7%
    {{-1, 1}, {1, 1}}}, // 10%
    // d = 3
    {{{1, -1}, {1, 1}},   // 1%
    {{0, -2}, {0, 2}},   // 2%
    {{-2, 0}},           // 5%
    {{0, -1}, {0, 1}},   // 7%
    {{-1, -1}, {-1, 1}}}, // 10%
};

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void Simulate(int x, int y, int d) {
    int cur = board[x][y];
    board[x][y] = 0;
    int one = cur / 100;
    int two = cur * 2 / 100;
    int five = cur * 5 / 100;
    int seven = cur * 7 / 100;
    int ten = cur * 10 / 100;

    int dust[] = {one, two, five, seven, ten};
    int moved = 0; // 다른 칸으로 이동하면 moved에 더하기 -> cur - moved = alpha 위치에 더하기

    for (int i = 0; i < dir[d].size(); i++) {
        for (int j = 0; j < dir[d][i].size(); j++) {
            int ndx, ndy;
            tie(ndx, ndy) = dir[d][i][j];
            int nx = x + ndx;
            int ny = y + ndy;
            if (InRange(nx, ny)) board[nx][ny] += dust[i];
            else answer += dust[i];
            moved += dust[i];
        }
    }

    // alpha 계산
    int alpha = cur - moved;
    int nx = x + dx[d];
    int ny = y + dy[d];
    if (!InRange(nx, ny)) answer += alpha;
    else board[nx][ny] += alpha;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    int x, y;
    x = y = n / 2;
    int dist = 0;

    while (true) {
        if (x == 0 && y == 0) break;
        for (int d = 0; d < 4; d++) {
            if (x == 0 && y == 0) break;
            if (d % 2 == 0) dist++;
            int tmp = dist;
            while (tmp--) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (!InRange(nx, ny)) break;
                Simulate(nx, ny, d);
                x = nx;
                y = ny;
            }
        }
    }
    cout << answer;
    return 0;
}