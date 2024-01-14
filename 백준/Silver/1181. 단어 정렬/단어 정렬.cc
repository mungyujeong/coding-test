#include <iostream>
#include <algorithm>

#define MAX_N 20'000

using namespace std;

int n;
pair<int, string> words[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        words[i] = {x.length(), x};
    }
    sort(words, words + n);
    string curr = words[0].second;
    cout << curr << '\n';

    for (int i = 1; i < n; i++) {
        if (curr == words[i].second) continue;
        curr = words[i].second;
        cout << curr << '\n';
    }
}