#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

deque<char> gear[4];
int k, answer, number, dir;

void move(int idx, int d) {
    if (d == 1) {
        gear[idx].push_front(gear[idx].back());
        gear[idx].pop_back();
    }
    else {
        gear[idx].push_back(gear[idx].front());
        gear[idx].pop_front();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            char x;
            cin >> x;
            gear[i].push_back(x);
        }
    }

    cin >> k;
    while (k--) {
        cin >> number >> dir;
        number--;
        queue<pair<int, int>> Q;
        vector<pair<int, int>> v;
        int visited[4] = {};
        visited[number] = 1;
        Q.push({number, dir});
        v.push_back({number, dir});

        int idx, d;
        while (!Q.empty()) {
            tie(idx, d) = Q.front();
            Q.pop();
            
            if (idx - 1 >= 0 && !visited[idx - 1] && gear[idx - 1][2] != gear[idx][6]) {
                v.push_back({idx - 1, -d});
                Q.push({idx - 1, -d});
                visited[idx - 1] = 1;
            }
            if (idx + 1 < 4 && !visited[idx + 1] && gear[idx + 1][6] != gear[idx][2]) {
                v.push_back({idx + 1, -d});
                Q.push({idx + 1, -d});
                visited[idx + 1] = 1;
            }
        }

        for (auto i : v) {
            tie(idx, d) = i;
            move(idx, d);
        }
    }

    for (int i = 0; i < 4; i++)
        if (gear[i][0] == '1')
            answer += pow(2, i);
    cout << answer;
}