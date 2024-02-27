#include <iostream>

using namespace std;

string x[5], answer;
int len;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 5; i++) {
        cin >> x[i];
        len = max(len, (int) x[i].size());
    }

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 5; j++) {
            if (x[j].size() <= i) continue;
            answer.push_back(x[j][i]);
        }
    }

    cout << answer;
}