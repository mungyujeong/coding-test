#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n, answer;
stack<int> stk;
vector<char> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int idx = 1;
    
    bool is_valid = true;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        if (stk.empty()) {
            while (idx <= x) {
                stk.push(idx++);
                v.push_back('+');
            }
        }

        else if (x > stk.top()) {
            while (idx <= x) {
                stk.push(idx++);
                v.push_back('+');
            }
        }
        
        if (x == stk.top()) {
            stk.pop();
            v.push_back('-');
        }
        else {
            cout << "NO\n";
            is_valid = false;
            break;
        }
    }

    if (is_valid) {
        for (auto i : v) 
            cout << i << '\n';
    }
}