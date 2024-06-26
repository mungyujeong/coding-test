#include <iostream>
#include <vector>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n) {
        if (n == -1) break;
        int sum = 0;
        vector<int> v;
        for (int i = 1; i < n; i++)
            if (n % i == 0) {
                sum += i;
                v.push_back(i);
            }
        
        if (n == sum) {
            cout << n << " = ";
            for (int i = 0; i < v.size() - 1; i++)
                cout << v[i] << " + ";
            cout << v.back() << '\n';
        }
        else cout << n << " is NOT perfect.\n";
    }       
}   