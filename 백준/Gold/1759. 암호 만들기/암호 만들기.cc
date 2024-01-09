#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 15

using namespace std;

int l, c;
char arr[MAX_N];
vector<char> result;

bool check(char i) {
    return (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u');
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> c;
    for (int i = 0; i < c; i++) 
        cin >> arr[i];
    sort(arr, arr + c);

    vector<int> v(c);
    for (int i = l; i < c; i++)
        v[i] = 1;
    
    do {
        string ans;
        int cnt = 0;
        for (int i = 0; i < c; i++) {
            if (v[i] == 0) {
                ans += arr[i];
                if (check(arr[i])) cnt++;
            }
        }
        if (cnt >= 1 && l - cnt >= 2) 
            cout << ans << '\n';

    } while (next_permutation(v.begin(), v.end()));
}