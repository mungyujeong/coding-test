#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int n, m, answer;
deque<int> DQ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        DQ.push_back(i);

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        int idx = find(DQ.begin(), DQ.end(), x) - DQ.begin();
        while (DQ.front() != x) {
            if (idx < (int)DQ.size() - idx) {
                DQ.push_back(DQ.front());
                DQ.pop_front();
            } else {
                DQ.push_front(DQ.back());
                DQ.pop_back();
            }
            answer++;
        }
        DQ.pop_front();
    }

    cout << answer;
}