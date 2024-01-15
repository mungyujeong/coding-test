#include <iostream>
#include <tuple>
#include <algorithm>

#define MAX_N 100'000

using namespace std;

int n;
pair<int, int> meeting[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        meeting[i] = make_pair(b, a);
    }
    sort(meeting, meeting + n);
    
    int cnt = 1;
    int st, en, nxst, nxen;
    tie(en, st) = meeting[0];
    for (int i = 1; i < n; i++) {
        tie(nxen, nxst) = meeting[i];
        if (nxst >= en) {
            cnt++;
            st = nxst;
            en = nxen;
        }
    }   
    cout << cnt;
}