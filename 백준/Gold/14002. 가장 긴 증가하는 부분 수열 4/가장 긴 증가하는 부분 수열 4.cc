#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 1'000

using namespace std;

int n, a[MAX_N], length[MAX_N];
vector<int> v[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < n; i++) {
        length[i] = 1;
        for (int j = 0; j < i; j++) 
            if (a[i] > a[j]) {
                if (length[i] < length[j] + 1) {
                    length[i] = length[j] + 1;
                    v[i] = v[j];
                    v[i].push_back(a[j]);
                }
            }
    }

    int idx = max_element(length, length + n) - length;
    cout << length[idx] << '\n';
    for (auto i : v[idx])
        cout << i << ' ';
    cout << a[idx];
}