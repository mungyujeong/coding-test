#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

#define MAX_N 100'000

using namespace std;

int n;
vector<tuple<int, int, int, string>> student;

int main() {
    cin >> n;
    string name;
    int kor, eng, math;
    for (int i = 0; i < n; i++) {
        cin >> name >> kor >> eng >> math;
        student.push_back({-kor, eng, -math, name});
    }
    sort(student.begin(), student.end());
    for (auto i : student) {
        tie (ignore, ignore, ignore, name) = i;
        cout << name << '\n';
    }
}