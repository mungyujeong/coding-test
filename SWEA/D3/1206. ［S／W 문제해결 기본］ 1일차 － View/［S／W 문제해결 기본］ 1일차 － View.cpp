#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;

int main() {
    for (int testcase = 1; testcase <= 10; testcase++) {
        cin >> n;
        vector<int> v(n);
        int answer = 0;

        for (int i = 0; i < n; i++)
            cin >> v[i];
        
        for (int i = 2; i < n - 2; i++) {
            if (v[i] < v[i - 1] || 
                v[i] < v[i - 2] || 
                v[i] < v[i + 1] || 
                v[i] < v[i + 2]) 
                continue;
            
            int max_value = INT_MIN;
            max_value = max(max_value, v[i - 1]);
            max_value = max(max_value, v[i - 2]);
            max_value = max(max_value, v[i + 1]);
            max_value = max(max_value, v[i + 2]);

            answer += v[i] - max_value;
        }

        cout << "#" << testcase << " " << answer << "\n";
    }

    return 0;
}