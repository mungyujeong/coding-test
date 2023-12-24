#include <iostream>

#define MAX_N 20

using namespace std;

int n;
int arr[MAX_N];
int y, m;

int main() {
    cin >> n;
    while(n--) {
        cin >> arr[n];
        y += (arr[n] / 30 + 1) * 10;
        m += (arr[n] / 60 + 1) * 15;
    }
    
    if (y < m) {
        cout << "Y " << y;    
    } else if (y > m) {
        cout << "M " << m;
    } else {
        cout <<"Y M " << y;
    }
    
    return 0;
}