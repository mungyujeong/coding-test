#include <iostream>

using namespace std;

int n, m, answer;
string str;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> str;

    for (int i = 0; i < m; i++) {
        int k = 0;
        if (str[i] == 'O') continue;
        while (str[i + 1] == 'O' && str[i + 2] == 'I') {
            k++;
            if (k == n) {
                answer++;
                k--;
            }
            i += 2;
        }
    }
    
    cout << answer;
}