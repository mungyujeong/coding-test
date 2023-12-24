#include <iostream>

using namespace std;

int main() {
    unsigned long long a, b;
    cin >> a >> b;
    
    if (a == b) {
        cout << 0;
        return 0;
    }
    
    unsigned long long t = a > b ? a - b - 1 : b - a - 1;
    unsigned long long min_val = min(a, b);
    
    cout << t << "\n";
    while(t--) {
        cout << ++min_val << " ";
    }

    return 0;
}