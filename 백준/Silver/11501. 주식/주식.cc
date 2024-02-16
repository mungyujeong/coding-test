#include <iostream>

#define MAX_N 1'000'000

using namespace std;
using ll = long long;

int test_case, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test_case;
    while (test_case--) {
        cin >> n;
        int arr[MAX_N];
        for (int i = 0; i < n; i++) 
            cin >> arr[i];
        
        ll max_val, answer;
        max_val = answer = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (max_val < arr[i]) max_val = arr[i];
            else answer += (max_val - arr[i]);
        }
        cout << answer << '\n';
    }
}