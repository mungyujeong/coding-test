#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 13

using namespace std;

int k;
int arr[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        cin >> k;
        if (k == 0) break;
        for (int i = 0; i < k; i++)
            cin >> arr[i];
        vector<int> v(6, 0);
        for (int i = 0; i < k - 6; i++)
            v.push_back(1);

        do {
            for (int i = 0; i < k; i++) 
                if (v[i] == 0)
                    cout << arr[i] << ' ';
            cout << '\n';
        } while (next_permutation(v.begin(), v.end()));
        cout << '\n';
    }
}