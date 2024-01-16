#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

#define MAX_N 1'000

using namespace std;

int n, w, L, answer, weight;
deque<int> truk;
vector<int> bridge;

void move() {
    if (bridge[0] != 0) {
        n--;
        weight -= bridge[0];
    }
    rotate(bridge.begin(), bridge.begin() + 1, bridge.end());
    bridge.pop_back();
    bridge.push_back(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> w >> L;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        truk.push_back(x);
    }

    for (int i = 0; i < w; i++)
        bridge.push_back(0);
    
    while (n > 0) {
        answer++;
        
        move();
        if (!truk.empty() && L >= weight + truk.front()) {
            bridge[w - 1] = truk.front();
            weight += truk.front();
            truk.pop_front();
        }
    }

    cout << answer;
}