#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 101

using namespace std;

int R, C, M, answer, cur;
// 위 오 아래 왼
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
tuple<int, int, int> board[MAX_N][MAX_N];
vector<tuple<int, int, int>> nxt_board[MAX_N][MAX_N];

bool in_range(int x, int y) {
	return 1 <= x && x <= R && 1 <= y && y <= C;
}

void move(int x, int y) {
	int s, d, z, nx, ny, len;
	tie(s, d, z) = board[x][y];
	if (d == 0 || d == 2) len = R - 1;
	else len = C - 1;
	nx = x; ny = y;
	for (int j = 0; j < s % (2 * len); j++) {
		if (!in_range(nx + dx[d], ny + dy[d])) d = (d + 2) % 4;
		nx += dx[d];
		ny += dy[d];
	}
	board[x][y] = { -1, -1, -1 };
	nxt_board[nx][ny].push_back({ s, d, z });
}

void eat(int x, int y) {
	int max_s, max_d, max_z;
	max_s = max_d = max_z = 0;
	for (auto i : nxt_board[x][y]) {
		int s, d, z;
		tie(s, d, z) = i;
		if (max_z < z) {
			max_z = z;
			max_s = s;
			max_d = d;
		}
	}

	board[x][y] = { max_s, max_d, max_z };
}

void simulate() {
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			nxt_board[i][j].clear();

	// 땅에 가까운 상어 잡기
	for (int i = 1; i <= R; i++) {
		int s, d, z;
		tie(s, d, z) = board[i][cur];
		if (s == -1) continue;
		answer += z;
		board[i][cur] = {};
		break;
	}

	// (i, j) 상어들 이동
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			move(i, j);

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++) {
			if (nxt_board[i][j].size() > 1)
				eat(i, j);
			else if (nxt_board[i][j].size() == 1)
				board[i][j] = nxt_board[i][j].front();
		}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C >> M;
	// board 초기화
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			board[i][j] = { -1, -1, -1 };

	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;

		if (d == 1) d = 0;
		else if (d == 2) d = 2;
		else if (d == 3) d = 1;
		else if (d == 4) d = 3;
		board[r][c] = { s, d, z };
	}

	for (int i = 0; i < C; i++) {
		cur++; // 낚시왕 이동
		simulate();
	}

	cout << answer;
}