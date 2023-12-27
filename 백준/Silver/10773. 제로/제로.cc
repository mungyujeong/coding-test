#include <iostream>
#include <stack>

using namespace std;

int k, answer;
stack<int> stk;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        if (!stk.empty() && x == 0) {
            answer -= stk.top();
            stk.pop();
        } else {
            stk.push(x);
            answer += x;
        }
    }
    cout << answer;
}