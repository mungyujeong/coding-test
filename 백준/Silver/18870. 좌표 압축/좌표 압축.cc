#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

#define MAX_N 1'000'000

using namespace std;

vector<int> x;
vector<int> origin;
unordered_map<int, int> m;
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        origin.push_back(t);
        if (m[t] > 0) continue;
        m[t] = 1;
        x.push_back(t);
    }
    sort(x.begin(), x.end());
    
    for (int i = 0; i < n; i++) 
        cout << lower_bound(x.begin(), x.end(), origin[i]) - x.begin() << ' ';
}