#include <iostream>
#include <queue>

using namespace std;

int n, answer, accumurate;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--) {
        int x;
        cin >> x;
        pq.push(x);
    }

    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        answer += a + b;

        // 합친 카드 묶음 다시 push
        pq.push(a + b);
    }
    
    cout << answer;

    return 0;
}