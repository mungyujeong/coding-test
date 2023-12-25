#include <iostream>

#define MAX_N 100000
#define OFFSET 1000000

using namespace std;

int n, x, answer;
int arr[MAX_N];
int freq[4 * OFFSET + 1];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> x;

    for (int i = 0; i < n; i++){ 
        int diff = x - arr[i] + OFFSET;
        if (freq[diff]) answer++;
        else freq[arr[i] + OFFSET] = 1;
    }

    cout << answer;

    return 0;
}