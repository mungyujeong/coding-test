#include <iostream>
#include <string>

using namespace std;

int arr[3];
int freq[10];

int main(void) {
    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }
    
    int mult = arr[0] * arr[1] * arr[2];
    string str = to_string(mult);
    
    for (int i = 0 ; i < str.size(); i++) {
        freq[str[i] - '0']++;
    }
    
    for (int i = 0; i < 10; i++)
        cout << freq[i] << "\n";
}