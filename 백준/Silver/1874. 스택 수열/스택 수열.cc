#include <iostream>
#include <stack>

using namespace std;

int n;
stack<int> stk;
string answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int idx = 1;
    
    bool is_valid = true;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        while (idx <= x) {
            stk.push(idx++);
            answer += "+\n";
        }   

        if (stk.top() != x) {
            cout << "NO\n";
            return 0;
        }
        stk.pop();
        answer += "-\n";
    }

    cout << answer;
}