#include <iostream>

using namespace std;

int main() {
    for (int i = 0; i < 3; i++) {
        int cnt = 0;
        for (int j = 0; j < 4; j++) {
            int x;
            cin >> x;
            if (x == 1) cnt++;
        }
        
        if (cnt == 0) {
            cout << "D" << "\n";
        } else if (cnt == 1) {
            cout << "C" << "\n";
        } else if (cnt == 2) {
            cout << "B" << "\n";
        } else if (cnt == 3){
            cout << "A" << "\n";
        } else {
            cout << "E" << "\n";
        }
    }
    return 0;
}