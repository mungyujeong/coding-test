#include <iostream>

using namespace std;

int student[31];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 28; i++) {
        int x;
        cin >> x;
        student[x] = 1;
    }

    int cnt = 0;
    for (int i = 1; i <= 30; i++) {
        if (student[i] == 0) {
            cout << i << '\n';
            cnt++;
        }
        if (cnt > 2) break;
    }
}