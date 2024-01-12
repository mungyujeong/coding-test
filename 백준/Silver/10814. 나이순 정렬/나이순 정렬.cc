#include <iostream>
#include <algorithm>
#include <tuple>

#define MAX_N 100000

using namespace std;

int n;
tuple<int, int, string> member[MAX_N];
int year;
string name;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> year >> name;
        member[i] = make_tuple(year, i, name);
    }

    sort(member, member + n);
    
    for (int i = 0; i < n; i++) {
        tie(year, ignore, name) = member[i];
        cout << year << ' ' << name << '\n';
    }
        
}