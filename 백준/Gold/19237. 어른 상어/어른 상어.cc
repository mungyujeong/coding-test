#include <iostream>
#include <tuple>

#define MAX_N 20
#define MAX_M 400
#define BLANK make_pair(0, 0)

using namespace std;

int n, m, k, board[MAX_N][MAX_N], dir[MAX_M], prior[MAX_M][4][4], nxt_board[MAX_N][MAX_N];
pair<int, int> contract[MAX_N][MAX_N];
bool is_alive[MAX_M];

// 상 하 좌 우
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void UpdateContract() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (contract[i][j] != BLANK) {
                int player, t;
                tie (player, t) = contract[i][j];
                contract[i][j] = (t - 1 == 0) ? BLANK : make_pair(player, t - 1);
            }
}

void NewContract() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j])
                contract[i][j] = make_pair(board[i][j], k);
}

void Initialize() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            nxt_board[i][j] = 0;
}

pair<int, int> FindPos(int player) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] == player + 1)
                return make_pair(i, j);
    
    return BLANK;
}

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int player, int d) {
    int x, y;
    tie(x, y) = FindPos(player);
    
    for (auto i : prior[player][d]) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!in_range(nx, ny)) continue;
        if (contract[nx][ny] != BLANK) continue;
        if (nxt_board[nx][ny]) {
            if (player + 1 < nxt_board[nx][ny]) {
                nxt_board[nx][ny] = player + 1;
                dir[player] = i;
            }
            else {
                is_alive[player] = false;
            }
            return true;
        }
        else {
            nxt_board[nx][ny] = player + 1;
            dir[player] = i;
            return true;
        }
    }

    return false;
}

void MoveToContracted(int player, int d) {
    int x, y;
    tie(x, y) = FindPos(player);
    
    for (auto i : prior[player][d]) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!in_range(nx, ny)) continue;
        if (contract[nx][ny] != BLANK) {
            int p, t;
            tie(p, t) = contract[nx][ny];
            if (p == player + 1) {
                nxt_board[nx][ny] = player + 1;
                dir[player] = i;
                return;
            }
        }
    }
}

void Move() {
    Initialize();

    for (int player = 0; player < m; player++) {
        if (!is_alive[player]) continue;
        if (!CanGo(player, dir[player])) 
            MoveToContracted(player, dir[player]);
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = nxt_board[i][j];
}

void Simulate() {
    Move();
    UpdateContract();
    NewContract();
}

bool IsAlive() {
    for (int i = 1; i < m; i++)
        if (is_alive[i])
            return true;
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j]) {
                is_alive[board[i][j] - 1] = true;
                contract[i][j] = make_pair(board[i][j], k);
            }
        }
    
    for (int i = 0; i < m; i++) {
        int d;
        cin >> d;
        dir[i] = d - 1;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 4; j++) {
            for (int t = 0; t < 4; t++) {
                int d;
                cin >> d;
                prior[i][j][t] = d - 1;
            }
        }
    }

    int turn = 0;
    while (turn <= 1000) {
        turn++;
        Simulate();
        if (!IsAlive()) break;
    }

    if (turn > 1000) cout << -1;
    else cout << turn;
}