#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 1'000

using namespace std;
using ll = long long;

int n, answer;
vector<int> u, twosum;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        u.push_back(x);
    }

    sort(u.begin(), u.end());
    for (int i = 0; i < u.size(); i++) 
        for (int j = i; j < u.size(); j++) 
            twosum.push_back(u[i] + u[j]);
    sort(twosum.begin(), twosum.end());
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (binary_search(twosum.begin(), twosum.end(), u[i] - u[j])) {
                cout << u[i];
                return 0;
            }
        }
    }
    
    cout << answer;
}