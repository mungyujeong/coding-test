#include <iostream>
#include <algorithm>
#include <string>

#define MAX_N 50

using namespace std;

int n;
tuple<int, int, string> guitars[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    string serial;
    for (int i = 0; i < n; i++) {
        cin >> serial;
        int cnt = 0;
        for (int j = 0; j < serial.length(); j++)
            if ('0' <= serial[j] && serial[j] <= '9') 
                cnt += serial[j] - '0';
        guitars[i] = make_tuple(serial.length(), cnt, serial);
    }
    sort(guitars, guitars + n);

    for (int i = 0; i < n; i++) {
        tie(ignore, ignore, serial) = guitars[i];
        cout << serial << '\n';
    }
}