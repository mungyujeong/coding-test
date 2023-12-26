#include <iostream>
#include <stack>

#define MAX_H 100000000

using namespace std;

int n;
stack<pair<int, int>> stk;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    stk.push({MAX_H + 1, 0});

    for (int i = 1; i <= n; i++) {
        int height;
        cin >> height;

        while (height > stk.top().first) 
            stk.pop();
        
        cout << stk.top().second << ' ';
        stk.push({height, i});
    }
    return 0;
}