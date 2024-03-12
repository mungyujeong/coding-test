#include <iostream>

#define MAX_N 50

using namespace std;

int n, m, T, answer, board[MAX_N][MAX_N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void Shift(int row, int d, int k) {
    int tmp[MAX_N] = {};
    
    // 시계 방향
    if (d == 0) {
        for (int i = 0; i < m; i++)
            tmp[(i + k) % m] = board[row][i];
    }
    else {
        for (int i = 0; i < m; i++)
            tmp[(i - k + m) % m] = board[row][i];
    }

    for (int i = 0; i < m; i++)
        board[row][i] = tmp[i];
}

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool Remove() {
    bool check[MAX_N][MAX_N];
    bool removed = false;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            check[i][j] = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j]) {
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = (j + dy[d] + m) % m;
                    if (!in_range(nx, ny)) continue;
                    if (board[nx][ny] == board[i][j])
                        check[i][j] = check[nx][ny] = true;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (check[i][j]) {
                removed = true;
                board[i][j] = 0;
            }
    
    return removed;
}

void Normalize() {
    double avg;
    int cnt;
    avg = cnt = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (board[i][j]) {
                avg += board[i][j];
                cnt++;
            }

    if (cnt) {
        avg /= cnt;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j]) {
                    if (board[i][j] > avg) board[i][j]--;
                    else if (board[i][j] < avg) board[i][j]++;
                }
    }
}

void Simulate(int x, int d, int k) {
    for (int i = 0; i < n; i++) 
        if ((i + 1) % x == 0)
            Shift(i, d, k);
    
    if (!Remove())
        Normalize();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> T;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    
    while (T--) {
        int x, d, k;
        cin >> x >> d >> k;
        Simulate(x, d, k);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            answer += board[i][j];
    
    cout << answer;
}