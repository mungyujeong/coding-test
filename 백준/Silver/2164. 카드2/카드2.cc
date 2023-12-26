#include <iostream>
#include <queue>
using namespace std;

int n;
queue<int> Q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        Q.push(i);
    
    while (Q.size() > 1) {
        Q.pop();
        Q.push(Q.front());
        Q.pop();
    }

    cout << Q.front();
}