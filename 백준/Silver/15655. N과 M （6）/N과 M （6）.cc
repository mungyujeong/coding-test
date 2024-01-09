#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 8

using namespace std;

int n, m;
int arr[MAX_N];

int main() {
    cin >> n >> m;
    vector<int> comb(m, 0);
    for (int i = 0; i < n - m; i++)
        comb.push_back(1);
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    sort(arr, arr + n);
    do {
        for (int i = 0; i < n; i++) 
            if (comb[i] == 0)
                cout << arr[i] << ' ';
        cout << endl;
    } while (next_permutation(comb.begin(), comb.end()));
}