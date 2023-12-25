#include <iostream>
#include <string>

using namespace std;

int freq[10];
int plastic[10];
string str;
int answer;

int main(void) {
    fill(freq, freq + 10, 1);
    
    cin >> str;
    for (auto i : str) {
        if (plastic[i - '0']) {
            plastic[i - '0']--;
        } else if ((i == '6' || i == '9') && 
                   !(plastic[6] == 0 && plastic[9] == 0)) {
            if (plastic[6] == 0)
                plastic[9]--;
            else if (plastic[9] == 0)
                plastic[6]--;
        } else {
            answer++;
            for (int j = 0; j < 10; j++)
                plastic[j] += freq[j];
            plastic[i - '0']--;
        }
    }
    
    cout << answer;
}