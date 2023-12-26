#include <iostream>
#include <stack>

using namespace std;

int n, answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--) {
        string str;
        cin >> str;

        stack<char> stk;
        for (auto s : str) {
            if (stk.empty()) {
                stk.push(s);
                continue;
            } 

            if (s == 'A') {
                if (stk.top() == 'A') {
                    stk.pop();
                } 
                else stk.push(s);
            }
            else if (s == 'B') {
                if (stk.top() == 'B') {
                    stk.pop();
                }
                else stk.push(s);
            }
        }

        if (stk.empty()) answer++;
    }
    cout << answer;
}