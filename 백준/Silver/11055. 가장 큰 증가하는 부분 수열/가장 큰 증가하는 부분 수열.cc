#include <iostream>
#include <algorithm>

using namespace std;

int n, d[1'001], sum[1'001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> d[i];
    
    for (int i = 0; i < n; i++) {
        sum[i] = d[i];
        for (int j = 0; j < i; j++) {
            if (d[i] > d[j]) {
                sum[i] = max(sum[i], d[i] + sum[j]);
            }
        }
    }

    cout << *max_element(sum, sum + n);
}