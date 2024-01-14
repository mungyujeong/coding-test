#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 1'000

using namespace std;

string s;
vector<string> v;

int main() {
    cin >> s;
    for (int i = 0; i < (int)s.length(); i++) 
        v.push_back(s.substr(i, s.length()));
    sort(v.begin(), v.end());
    for (auto s : v)
        cout << s << '\n';
}