#include <iostream>
#include <deque>
#include <unordered_map>

using namespace std;

int n, m, answer;
deque<int> DQ;
unordered_map<int, int> map;

void update() {
    int size = DQ.size();

    for (int i = 1; i <= size; i++) {
        map[DQ.front()] = i;
        DQ.push_back(DQ.front());
        DQ.pop_front();
    }
}

void left() {
    int front = DQ.front();
    DQ.push_back(front);
    DQ.pop_front();
    answer++;

    update();
}

void right() {
    DQ.push_front(DQ.back());
    DQ.pop_back();
    answer++;

    update();
}

void remove() {
    map[DQ.front()] = -1;
    DQ.pop_front();
    update();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        DQ.push_back(i);
        map[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        // cout << "map[t]\n";
        // for (int t = 1; t <= 10; t++)
        //     cout << t << ": " << map[t] << '\n';
        // cout << endl;
        // cout << "front: " << DQ.front() << '\n';

        if (x == DQ.front()) {
            remove();
            continue;
        }

        int left_time = map[x] - 1;
        int right_time = DQ.size() - map[x] + 1;

        if (left_time > right_time) {
            while(right_time--)
                right();
        } else {
            while (left_time--)
                left();
        }

        remove();
    }

    cout << answer;
}