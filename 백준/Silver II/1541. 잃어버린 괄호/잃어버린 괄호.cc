#include <iostream>
#include <string>

using namespace std;

string input, num;
bool is_minus;
int answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> input;

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '-' || input[i] == '+') {
            if (is_minus) answer -= stoi(num);
            else answer += stoi(num);
            num.clear();
        }
        else num += input[i];
        
        if (input[i] == '-') is_minus = true;
    }

    if (is_minus) answer -= stoi(num);
    else answer += stoi(num);

    cout << answer;
}