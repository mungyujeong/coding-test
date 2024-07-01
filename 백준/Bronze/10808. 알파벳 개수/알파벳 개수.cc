#include <iostream>

using namespace std;

string S;
int cnt[26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> S;
    for (char s : S)
        cnt[s - 'a']++;
    
    for (int i : cnt)
        cout << i << ' ';
}