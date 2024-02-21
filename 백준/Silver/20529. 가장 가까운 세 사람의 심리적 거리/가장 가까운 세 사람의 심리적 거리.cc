#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <climits>

using namespace std;

int test_case, n;

int diff(string a, string b, string c) {
    int cnt = 0;
    for (int i = 0; i < 4; i++)
        cnt += (a[i] != b[i]) + (b[i] != c[i]) + (c[i] != a[i]);
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> test_case;

    while (test_case--) {
        cin >> n;
        vector<string> v;
        unordered_map<string, int> map;
        int answer = INT_MAX;

        for (int i = 0; i < n; i++) {
            string mbti;
            cin >> mbti;
            map[mbti]++;
            if (map[mbti] <= 3) v.push_back(mbti);
        }

        int sz = v.size();
        for (int i = 0; i < sz; i++) 
            for (int j = i + 1; j < sz; j++) 
                for (int k = j + 1; k < sz; k++) 
                    answer = min(answer, diff(v[i], v[j], v[k]));

        cout << answer << '\n';
    }
}