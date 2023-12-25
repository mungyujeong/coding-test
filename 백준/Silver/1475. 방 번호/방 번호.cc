#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int freq[10];
string str;
int answer;

int main(void) {
    
    cin >> str;
    for (auto i : str) {
        int idx = i - '0';
        
        if (idx == 9 || idx == 6) {
            if (freq[6] > freq[9])
                freq[9]++;
            else
                freq[6]++;
        } else {
            freq[idx]++;
        }
    }
    
    answer = *max_element(freq, freq + 10);
    
    cout << answer;
}