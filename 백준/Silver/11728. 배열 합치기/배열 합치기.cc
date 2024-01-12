#include <iostream>
#include <deque>
#include <vector>

#define MAX_N 1000000

using namespace std;

int n, m;
deque<int> a;
deque<int> b;
vector<int> result;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        cin >> x;
        b.push_back(x);
    }
    
    int limit = n + m;
    int ax, bx, idx = 0;
    while (limit-- && !a.empty() && !b.empty()) {
        ax = a.front();
        bx = b.front();
        if (ax > bx) {
            result.push_back(bx);
            b.pop_front();
        }
        else {
            result.push_back(ax);
            a.pop_front();
        }
    }

    if (a.empty() && !b.empty()) {
        while (!b.empty()) {
            result.push_back(b.front());
            b.pop_front();
        }
    }
    if (b.empty() && !a.empty()) {
        while (!a.empty()) {
            result.push_back(a.front());
            a.pop_front();
        }
    }
    
    for (auto i : result)
        cout << i << ' ';
}