#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        string str;
        getline(cin, str);

        if (str == ".") 
            break;
        
        stack<char> stk;
        string answer = "yes";
        for (auto s : str) {
            if (s == '(' || s == '[')
                stk.push(s);
            
            else if (s == ')') {
                if (stk.empty()) {
                    answer = "no";
                    break;
                }

                if (stk.top() == '(') {
                    stk.pop();
                } else {
                    answer = "no";
                    break;
                }
            } 
            else if (s == ']') {
                if (stk.empty()) {
                    answer = "no";
                    break;
                }

                if (stk.top() == '[') {
                    stk.pop();
                } else {
                    answer = "no";
                    break;
                }
            }
        }

        if (!stk.empty()) answer = "no";
        cout << answer << '\n';
    }
}