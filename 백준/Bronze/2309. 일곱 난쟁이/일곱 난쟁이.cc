#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[9];
vector<int> v;

int main() {
    int t = 9, sum = 0;
    while(t--) {
        cin >> arr[t];
        sum += arr[t];
    }
    

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            
            if (sum - arr[i] - arr[j] == 100) {
                
                for (int k = 0; k < 9; k++) {
                    if (i == k || j == k) continue;
                    v.push_back(arr[k]);
                }
                
                sort(v.begin(), v.end());
                
                for (auto k : v) {
                    cout << k << "\n";
                }
                
                return 0;
            }
        }
    }

    return 0;
}