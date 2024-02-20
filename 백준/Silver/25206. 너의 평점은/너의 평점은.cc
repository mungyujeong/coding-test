#include <iostream>
#include <unordered_map>

using namespace std;

string name, score;
double times, total;
double answer;
unordered_map<string, double> mapping;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    mapping["A+"] = 4.5;
    mapping["A0"] = 4.0;
    mapping["B+"] = 3.5;
    mapping["B0"] = 3.0;
    mapping["C+"] = 2.5;
    mapping["C0"] = 2.0;
    mapping["D+"] = 1.5;
    mapping["D0"] = 1.0;
    mapping["F"] = 0;

    for (int i = 0; i < 20; i++) {
        cin >> name >> times >> score;
        if (score == "P") continue;
        answer += times * mapping[score];
        total += times;
    }

    cout<<fixed;
    cout.precision(6);

    cout << answer / total;
}