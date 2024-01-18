#include <iostream>
#include <vector>

#define MAX_N 100

using namespace std;

int n, L;
int board[MAX_N][MAX_N];

bool check(vector<int>& v) {
    int idx = 0;
    int cnt = 1;
    while (idx + 1 < n) {
        if (abs(v[idx + 1] - v[idx]) > 1) return 0;

        if (v[idx] == v[idx + 1]) {
            cnt++;
            idx++;
        }
        else if (v[idx] < v[idx + 1]) {
            if (cnt < L) return 0;
            cnt = 1;
            idx++;
        }
        else {
            if (idx + L >= n) return 0;
            for (int i = idx + 1; i < idx + L; i++)
                if (v[i] != v[i + 1]) return 0;
            idx = idx + L;
            cnt = 0;
        }
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> L;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    int answer = 0;

    for (int i = 0; i < n; i++) {
        vector<int> line;
        for (int j = 0; j < n; j++)
            line.push_back(board[i][j]);
        answer += check(line);
    }

    for (int i = 0; i < n; i++) {
        vector<int> line;
        for (int j = 0; j < n; j++)
            line.push_back(board[j][i]);
        answer += check(line);
    }

    cout << answer;
}