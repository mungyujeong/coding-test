#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 15

using namespace std;

int l, c;
char arr[MAX_N];
vector<char> result;

bool check() {
    bool type1 = false;
    int cnt = 0;
    for (auto i : result) {
        if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
            type1 = true;
        else cnt++;
    }
    if (type1 && cnt >= 2) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> c;
    for (int i = 0; i < c; i++) 
        cin >> arr[i];
    vector<int> v(l, 0);
    for (int i = 0; i < c - l; i++)
        v.push_back(1);
    
    sort(arr, arr + c);
    do {
        for (int i = 0; i < c; i++)
            if (v[i] == 0)
                result.push_back(arr[i]);
        
        if (check()) {
            for (auto i : result)
                cout << i;
            cout << '\n';
        }
        result.clear();
    } while (next_permutation(v.begin(), v.end()));
}