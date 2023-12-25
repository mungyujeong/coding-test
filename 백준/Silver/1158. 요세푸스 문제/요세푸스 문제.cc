#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, k;
queue<int> q;

int main(void) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        q.push(i);
    
    int idx = 0;
    cout << '<';
    while(!q.empty()) {
        for (int i = 0; i < k - 1; i++) {
            q.push(q.front());
            q.pop();
        }

        cout << q.front();
        q.pop();
        if (q.size())
            cout << ", ";
    }
    cout << '>';
}