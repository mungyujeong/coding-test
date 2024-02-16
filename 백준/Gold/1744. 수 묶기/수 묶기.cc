#include <iostream>
#include <algorithm>

#define MAX_N 1'000
#define NONE 1'001

using namespace std;
using ll = long long;

ll n, arr[MAX_N], answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr + n, greater<ll>());
    
    ll a, b;
    a = b = NONE;
    int idx = 0;
    // 1은 더하기
    // 0은 매칭안되는 최소 마이너스랑 매칭
    // 음수끼리, 양수끼리 큰 수끼리 매칭
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            answer += 1;
            continue;
        }
        if (arr[i] <= 0) {
            idx = i;
            break;
        }

        if (a == NONE) a = arr[i];
        else if (b == NONE) b = arr[i];
        else {
            answer += (a * b);
            a = arr[i];
            b = NONE;
        }
    }

    if (a != NONE && b != NONE) answer += (a * b);
    else if (a != NONE) answer += a;

    a = b = NONE;
    // 음수 매칭
    for (int i = n - 1; i >= idx; i--) {
        if (arr[i] > 0) break;
        
        if (a == NONE) a = arr[i];
        else if (b == NONE) b = arr[i];
        else {
            answer += (a * b);
            a = arr[i];
            b = NONE;
        }
    }

    if (a != NONE && b != NONE) answer += (a * b);
    else if (a != NONE) answer += a;

    cout << answer;
}