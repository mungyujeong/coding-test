#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

string s, e, q;
unordered_map<string, bool> before;
unordered_map<string, bool> after;
unordered_set<string> student;
int answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> e >> q;
    string time, name;
    while (cin >> time >> name) {
        student.insert(name);
        if (time <= s) before[name] = true;
        if (e <= time && time <= q) after[name] = true;
    }

    for (auto i : student) 
        if (before[i] && after[i])
            answer++;

    cout << answer;
}