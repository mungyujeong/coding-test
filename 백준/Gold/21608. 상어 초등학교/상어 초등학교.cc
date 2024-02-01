#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>

#define MAX_N 22

using namespace std;

int n, board[MAX_N + 1][MAX_N + 1], answer, arr[MAX_N * MAX_N][5], idx[MAX_N * MAX_N + 1];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool InRange(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n * n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
        idx[arr[i][0]] = i;
    }
    
    for (int i = 0; i < n * n; i++) {
        int student = arr[i][0];

        int r, c, max_favor, max_empty;
        r = c = max_favor = max_empty = -1;

        // 교실 탐색
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                if (board[x][y]) continue;
                int empty = 0;
                int favor = 0;
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (!InRange(nx, ny)) continue;
                    // 비어있는 칸 세기
                    if (board[nx][ny] == 0) empty++;
                    // 좋아하는 학생 수 세기
                    for (int t = 1; t < 5; t++)
                        if (board[nx][ny] == arr[i][t])
                            favor++;
                }

                if (max_favor < favor) {
                    r = x;
                    c = y;
                    max_favor = favor;
                    max_empty = empty;
                }
                else if (max_favor == favor && max_empty < empty) {
                    r = x;
                    c = y;
                    max_empty = empty;
                }
            }
        }

        board[r][c] = student;
    }

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            int favor = 0;
            int student = board[x][y];
            int favor_idx = idx[student];

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (!InRange(nx, ny)) continue;
                // 좋아하는 학생 수 세기
                for (int t = 1; t < 5; t++)
                    if (board[nx][ny] == arr[favor_idx][t])
                        favor++;
            }   

            if (favor != 0) answer += pow(10, favor - 1);
        }
    }

    cout << answer;
}