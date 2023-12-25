#include <iostream>
#include <stack>
#include <string>

using namespace std;

int n;
stack<int> stk;

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (str == "push") {
            int x;
            cin >> x;
            stk.push(x);
        } else if (str == "top") {
            if (stk.empty()) cout << -1 << "\n";
            else cout << stk.top() << "\n";
        } else if (str == "size") {
            cout << stk.size() << "\n";
        } else if (str == "pop") {
            if (!stk.empty()) {
                cout << stk.top() << "\n";
                stk.pop();
            } else {
                cout << -1 << "\n";
            }
        } else if (str == "empty") {
            if (stk.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
    
    return 0;
}