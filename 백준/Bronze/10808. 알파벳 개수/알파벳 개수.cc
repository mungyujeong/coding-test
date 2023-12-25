#include <iostream>
#include <string>

using namespace std;

string str;
int arr[26];

int main(void) {
    cin >> str;

    for (int i = 0; i < str.size(); i++) 
        arr[str[i] - 'a']++;
    
    for (int i = 0; i < 26; i++)
        cout << arr[i] << ' ';
}