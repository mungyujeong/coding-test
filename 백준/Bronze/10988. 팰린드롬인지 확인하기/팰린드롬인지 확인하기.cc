#include <iostream>

using namespace std;

string str;

int palindrome() {
    int sz = str.size();
    for (int i = 0; i < sz; i++) 
        if (str[i] != str[sz - i - 1]) 
            return 0;

    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    cout << palindrome();    
}