#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int n;
stack<int> stk;
string str;

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        int cnt = 0;
        string answer = "YES";

        for (auto i : str) {
            if (i == '(') cnt++;
            else cnt--;

            if (cnt < 0) {
                answer = "NO";
                break;
            }
        }
        
        if (cnt != 0) answer = "NO";
        cout << answer << "\n";
    }    
    return 0;
}