#include <iostream>
#include <deque>
using namespace std;

deque<int> DQ;
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i  = 0; i < n; i++) {
        string str;
        cin >> str;
        if (str == "push_front") {
            int x;
            cin >> x;
            DQ.push_front(x);
        } else if (str == "push_back") {
            int x;
            cin >> x;
            DQ.push_back(x);
        } else if (str == "pop_front") {
            if (DQ.empty()) cout << -1 << '\n';
            else {
                cout << DQ.front() << '\n';
                DQ.pop_front();
            }
        } else if (str == "pop_back") {
            if (DQ.empty()) cout << -1 << '\n';
            else {
                cout << DQ.back() << '\n';
                DQ.pop_back();
            }
        } else if (str == "size") {
            cout << DQ.size() << '\n';
        } else if (str == "empty") {
            cout << DQ.empty() << '\n';
        } else if (str == "front") {
            if (DQ.empty()) cout << -1 << '\n';
            else cout << DQ.front() << '\n';
        } else {
            // back
            if (DQ.empty()) cout << -1 << '\n';
            else cout << DQ.back() << '\n';
        }
    }
}