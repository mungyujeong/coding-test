#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

#define MAX_N 100

using namespace std;

int n;
int arr[MAX_N];
int operation[4];
vector<int> v;
int min_ans = INT_MAX;
int max_ans = INT_MIN;

int get_result() {
    int a = arr[0];
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0) a += arr[i + 1];
        else if (v[i] == 1) a -= arr[i + 1];
        else if (v[i] == 2) a *= arr[i + 1];
        else a /= arr[i + 1];
    }

    return a;
}

void backtracking(int depth) {
    if (depth == n - 1) {
        int result = get_result();
        min_ans = min(min_ans, result);
        max_ans = max(max_ans, result);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (operation[i] == 0) continue;
        v.push_back(i);
        operation[i]--;
        backtracking(depth + 1);
        v.pop_back();
        operation[i]++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = 0; i < 4; i++) 
        cin >> operation[i];
    
    backtracking(0);
    cout << max_ans << '\n' << min_ans;
}