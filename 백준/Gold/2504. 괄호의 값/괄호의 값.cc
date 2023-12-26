#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;
stack<char> stk1;
stack<char> stk2;
int tmp, answer, result;

int main() {
    cin >> str;
    for (int i = 0; i < str.size(); i++) {

        // cout << i << " " << tmp << " " << answer << " " << result << endl;

        if (str[i] == '(') {
            stk1.push(str[i]);
        } 

        else if (str[i] == '[') {
            stk2.push(str[i]);
        } 

        else if (str[i] == ')') {
            if (stk1.empty()) {
                cout << 0;
                return 0;
            }

            stk1.pop();

            if (str[i - 1] == '(') {
                if (stk1.empty() && stk2.empty()) answer += 2;
                else {
                    int tmp = 2;
                    for (int i = 0; i < stk1.size(); i++)
                        tmp *= 2;
                    for (int i = 0; i < stk2.size(); i++)
                        tmp *= 3;
                    answer += tmp;
                }
            } 
        } 

        else {
            if (stk2.empty()) {
                cout << 0;
                return 0;
            }

            stk2.pop();

            if (str[i - 1] == '[') {
                if (stk1.empty() && stk2.empty()) answer += 3;
                else {
                    int tmp = 3;
                    for (int i = 0; i < stk1.size(); i++)
                        tmp *= 2;
                    for (int i = 0; i < stk2.size(); i++)
                        tmp *= 3;
                    answer += tmp;
                }
            }
        }
    }

    if (stk1.empty() && stk2.empty())
        cout << answer;
    else 
        cout << 0;

    return 0;
}