#include <iostream>

using namespace std;

char arr[5] = {'D', 'C', 'B', 'A', 'E'};

int main() {
    for (int i = 0; i < 3; i++) {
        int x, cnt = 0, j = 4;
        while(j--) {
            cin >> x;
            cnt += x;
        }
        
        cout << arr[cnt] << "\n";
    }
    return 0;
}