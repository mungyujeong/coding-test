#include <iostream>
#include <string>

using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b;
        int freq[26] = {};
        cin >> a >> b;

        for (auto i : a) 
            freq[i - 'a']++;
        for (auto i : b)
            freq[i - 'a']--;
        
        string answer = "Possible";
        for (auto i : freq) {
            if (i != 0) {
                answer = "Impossible";
                break;
            }
        }

        cout << answer << "\n";
    }
    return 0;
}