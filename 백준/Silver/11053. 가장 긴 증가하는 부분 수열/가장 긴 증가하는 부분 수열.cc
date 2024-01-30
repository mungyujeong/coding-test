#include <iostream>
#include <algorithm>

#define MAX_N 1'000

using namespace std;

int n, a[MAX_N], length[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < n; i++) {
        length[i] = 1;
        for (int j = 0; j < i; j++) 
            if (a[i] > a[j]) 
                length[i] = max(length[i], length[j] + 1);
    }

    cout << *max_element(length, length + n);
}