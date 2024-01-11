#include <iostream>
#include <vector>

#define MAX_N 40
#define MAX_K 100

using namespace std;

int n, m, k, r, c, answer;
int laptop[MAX_N][MAX_N];
int sticker[MAX_N][MAX_N];

bool possible() {
    if (n < r || m < c) return false;
    bool ps = true;
    for (int i = 0; i <= n - r; i++) {
        for (int j = 0; j <= m - c; j++) {
            ps = true;
            for (int t = i; t < i + r; t++) {
                for (int l = j; l < j + c; l++) {
                    if (laptop[t][l] == 1 && sticker[t - i][l - j] == 1) 
                        ps = false;
                }
            }

            if (ps) {
                for (int t = i; t < i + r; t++) {
                    for (int l = j; l < j + c; l++) {
                        if (sticker[t - i][l - j] == 1) {
                            laptop[t][l] = 1;
                            answer++;
                        }
                    }
                }
                break;
            }
        }
        if (ps) break;
    }

    // cout << "possible: " << ps << '\n';
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << laptop[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    return ps;
}

void rotate() {
    int tmp[MAX_N][MAX_N] = {};

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) 
            tmp[j][r - 1 - i] = sticker[i][j];

    for (int i = 0; i < c; i++)
        for (int j = 0; j < r; j++)
            sticker[i][j] = tmp[i][j];

    swap(c, r);
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> r >> c;

        for (int j = 0; j < MAX_N; j++)
            fill(sticker[j], sticker[j] + MAX_N, 0);

        for (int j = 0; j < r; j++) 
            for (int t = 0; t < c; t++) 
                cin >> sticker[j][t];
        
        // simulation
        int cnt = 1;
        while (!possible() && cnt < 4) {
            rotate();
            cnt++;
        }
    }

    cout << answer;
}