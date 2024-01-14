#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

#define MAX_N 100'000

using namespace std;

int n;
vector<tuple<int, int, int, string>> student;

int cmp(tuple<int, int, int, string> a, tuple<int, int, int, string> b) {
    int kor1, kor2, eng1, eng2, math1, math2;
    string name1, name2;
    tie(kor1, eng1, math1, name1) = a;
    tie(kor2, eng2, math2, name2) = b;

    if (kor1 != kor2)
        return a > b;
    if (eng1 != eng2)
        return a < b;
    if (math1 != math2)
        return a > b;
    if (name1 != name2)
        return a < b;

    return a > b;
}

int main() {
    cin >> n;
    string name;
    int kor, eng, math;
    for (int i = 0; i < n; i++) {
        cin >> name >> kor >> eng >> math;
        student.push_back({kor, eng, math, name});
    }
    sort(student.begin(), student.end(), cmp);
    for (auto i : student) {
        tie (ignore, ignore, ignore, name) = i;
        cout << name << '\n';
    }
}