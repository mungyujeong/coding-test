#include <iostream>
#include <vector>

using namespace std;

int answer, cnt;
int blue[4][6], green[6][4];
vector<vector<int>> v[3] = {
    {{1, 0},
    {0, 0}},
    {{1, 1},
    {0, 0}},
    {{1, 0},
    {1, 0}},
};

bool IsGreenValid() {
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 4; j++)
            if (green[i][j] > 1)
                return false;
    return true;
}

bool IsBlueValid() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 6; j++)
            if (blue[i][j] > 1)
                return false;
    return true;
}

bool GravityGreen(int row, int col, vector<vector<int>> block) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int nx = row + i;
            int ny = col + j;
            if (nx < 6 && ny < 4) green[nx][ny] += block[i][j];
            else if (block[i][j]) return false;
        }
    }

    return true;
}

bool GravityBlue(int row, int col, vector<vector<int>> block) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int nx = row + i;
            int ny = col + j;
            if (nx < 4 && ny < 6) blue[nx][ny] += block[i][j];
            else if (block[i][j]) return false;
        }
    }

    return true;
}

bool CheckRow(int row) {
    for (int col = 0; col < 4; col++)
        if (green[row][col] == 0) 
            return false;

    return true;
}

bool CheckCol(int col) {
    for (int row = 0; row < 4; row++)
        if (blue[row][col] == 0) 
            return false;

    return true;
}

void DeleteRow(int row) {
    // row보다 작은 곳 한칸씩 내리기
    for (int i = row; i > 0; i--)
        for (int j = 0; j < 4; j++)
            green[i][j] = green[i - 1][j];
}

void DeleteCol(int col) {
    for (int i = col; i > 0; i--)
        for (int j = 0; j < 4; j++)
            blue[j][i] = blue[j][i - 1];
}

void Green(int type, int col) {
    vector<vector<int>> block = v[type];
    bool is_valid = true;
    int backup[6][4], idx;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 4; j++)
            backup[i][j] = green[i][j];

    for (int row = 0; row < 6; row++) {
        // 겹치면 무효       
        if (GravityGreen(row, col, block) && IsGreenValid()) {
            idx = row;
            for (int i = 0; i < 6; i++)
                for (int j = 0; j < 4; j++)
                    green[i][j] = backup[i][j];
        }
        else {
            for (int i = 0; i < 6; i++)
                for (int j = 0; j < 4; j++)
                    green[i][j] = backup[i][j];
            break;
        }
    }

    // idx에 추가
    GravityGreen(idx, col, block);
    // 모든 row에 값이 있으면 점수++ && 한 칸 이동
    for (int row = 5; row >= 0; row--)
        if (CheckRow(row)) {
            answer++;
            DeleteRow(row);
            row++;
        }
    
    // 연한 곳(row 0 ~ 1)에 값이 있을 경우 맨 아래 삭제
    int tmp = 0;
    for (int row = 1; row >= 0; row--) {
        for (int col = 0; col < 4; col++) {
            if (green[row][col]) {
                DeleteRow(5);
                break;
            }
        }
    }

    for (int row = 1; row >= 0; row--)
        for (int col = 0; col < 4; col++)
            green[row][col] = 0;
}

void Blue(int type, int row) {
    vector<vector<int>> block = v[type];
    bool is_valid = true;
    int backup[4][6], idx;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 6; j++)
            backup[i][j] = blue[i][j];

    for (int col = 0; col < 6; col++) {
        // 겹치면 무효       
        if (GravityBlue(row, col, block) && IsBlueValid()) {
            idx = col;
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 6; j++)
                    blue[i][j] = backup[i][j];
        }
        else {
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 6; j++)
                    blue[i][j] = backup[i][j];
            break;
        }
    }

    // idx에 추가
    GravityBlue(row, idx, block);
    // 모든 row에 값이 있으면 점수++ && 한 칸 이동
    for (int col = 5; col >= 0; col--)
        if (CheckCol(col)) {
            answer++;
            DeleteCol(col);
            col++;
        }
    
    // 연한 곳(row 0 ~ 1)에 값이 있을 경우 맨 아래 삭제
    int tmp = 0;
    for (int col = 1; col >= 0; col--) {
        for (int row = 0; row < 4; row++) {
            if (blue[row][col]) {
                DeleteCol(5);
                break;
            }
        }
    }
    for (int col = 1; col >= 0; col--)
        for (int row = 0; row < 4; row++)
            blue[row][col] = 0;
}

void Simulate(int type, int x, int y) {
    Green(type, y);
    Blue(type, x);
}

void Count() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 6; j++)
            if (blue[i][j])
                cnt++;

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 4; j++)
            if (green[i][j])
                cnt++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    while (n--) {
        int t, x, y;
        cin >> t >> x >> y;
        Simulate(t - 1, x, y);
    }

    Count();

    cout << answer << '\n' << cnt;
}