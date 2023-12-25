#include <iostream>
#include <stack>

using namespace std;

int n, answer;
string str;
stack<char> stk;

int main(void) {
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') 
            stk.push(str[i]);
        else {
            stk.pop();
            if (str[i - 1] == ')') answer += 1;
            else answer += stk.size();
        }
    }
    cout << answer;
    return 0;
}