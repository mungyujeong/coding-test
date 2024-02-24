#include <iostream>

using namespace std;

int n, m, answer;
string str, io;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> str;

    io = "I";
    while (n--) {
        io += "OI";
    }

    int sz = str.size();
    int len = io.size();

    for (int i = 0; i < sz; i++) {
        if (i + len > sz) break;
        if (str.substr(i, len) == io)
            answer++;
    }
    
    cout << answer;
}