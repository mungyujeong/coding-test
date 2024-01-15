#include <iostream>
#include <tuple>
#include <algorithm>

#define MAX_N 100'000

using namespace std;

int n;
int rope[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> rope[i];

    sort(rope, rope + n, greater<int>());

    int weight = 0;
    for (int i = 1; i <= n; i++) {
        weight = max(weight, rope[i - 1] * i);
    }
    
    cout << weight;
}