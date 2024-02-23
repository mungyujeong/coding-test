#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

int m, arr[11], answer = INT_MAX, sz;
string n, number;
vector<char> buttons;

void backtracking(int cur) {
    if (cur != 0 && cur == sz - 1 || cur == sz || cur == sz + 1) {
        // cout << stoi(number) << ' ';
        int result = stoi(number);
        string tmp = to_string(result);
        answer = min(answer, abs(stoi(n) - result) + int(tmp.size()));

        if (cur == sz + 1) return;
    }

    for (auto i : buttons) {
        number += i;
        backtracking(cur + 1);
        number.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> m;
    sz = n.size();
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        arr[x] = 1;
    }

    for (int i = 0; i < 10; i++)
        if (!arr[i])
            buttons.push_back(i + '0');

    backtracking(0);

    answer = min(answer, abs(100 - stoi(n)));
    cout << answer;
}