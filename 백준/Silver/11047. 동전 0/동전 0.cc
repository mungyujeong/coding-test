#include <iostream>
#include <vector>

#define MAX_N 10

using namespace std;

int n, k;
int coin[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) 
        cin >> coin[i];
    
    int cnt = 0;
    while (k != 0) {
        int i;
        for (i = 0; i < n; i++)
            if (k < coin[i]) break;
        cnt += k / coin[i - 1];
        k %= coin[i - 1];
    }
    cout << cnt;
}