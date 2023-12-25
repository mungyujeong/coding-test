#include <iostream>

using namespace std;

string str1, str2;
int freq[26];
int answer;

int main() {
    cin >> str1;
    cin >> str2;

    for (auto i : str1)
        freq[i - 'a']++;
    for (auto i : str2)
        freq[i - 'a']--;
    
    for (auto i : freq) {
        answer += abs(i);
    }
    cout << answer;
    return 0;
}