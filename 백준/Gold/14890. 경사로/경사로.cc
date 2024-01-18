#include <iostream>

#define MAX_N 100

using namespace std;

int n, L;
int board[MAX_N][MAX_N];

int main() {
    cin >> n >> L;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    int cnt = 2 * n;
    int cl = 0;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        int cr = 0;
        curr = board[i][0];
        cl = 1;
        for (int j = 1; j < n; j++) {
            if (curr == board[i][j]) {
                cl++;
                continue;
            }
            else if (curr == board[i][j] + 1) {
                int tmp = j;
                cr = 1;
                while (tmp + 1 < n && cr < L) {
                    tmp++;
                    if (board[i][tmp] == board[i][j]) cr++;
                    else break;

                    if (cr >= L) break;
                }

                if (cr >= L) {
                    j = tmp;
                    curr = board[i][tmp];
                    cl = 0;
                }
                else {
                    // cout << i << ", " <<  j << ": impossible\n";
                    cnt--;
                    break;
                }
            }
            else if (curr == board[i][j] - 1) {
                if (cl >= L) {
                    curr = board[i][j];
                    cl = 1;
                }
                else {
                    // cout << i << ", " <<  j << ": impossible\n";
                    cnt--;
                    break;
                }
            }
            else {
                // cout << i << ", " <<  j << ": impossible\n";
                cnt--;
                break;
            }
        }
        // cout << cnt << endl;
    }

    cl = 0;
    curr = 0;
    for (int i = 0; i < n; i++) {
        int cr = 0;
        curr = board[0][i];
        cl = 1;
        for (int j = 1; j < n; j++) {
            if (curr == board[j][i]) {
                cl++;
                continue;
            }
            else if (curr == board[j][i] + 1) {
                int tmp = j;
                cr = 1;
                while (tmp + 1 < n && cr < L) {
                    tmp++;
                    if (board[tmp][i] == board[j][i]) cr++;
                    else break;

                    if (cr >= L) break;
                }

                if (cr >= L) {
                    j = tmp;
                    curr = board[tmp][i];
                    cl = 0;
                }
                else {
                    // cout << i << ", " <<  j << ": + 1 impossible\n";
                    cnt--;
                    break;
                }
            }
            else if (curr == board[j][i] - 1) {
                if (cl >= L) {
                    curr = board[j][i];
                    cl = 1;
                }
                else {
                    // cout << i << ", " <<  j << ": - 1 impossible\n";
                    cnt--;
                    break;
                }
            }
            else {
                // cout << i << ", " <<  j << ": else impossible\n";
                cnt--;
                break;
            }
        }
    }
    cout << cnt << endl;
}