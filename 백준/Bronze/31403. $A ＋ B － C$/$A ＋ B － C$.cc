#include <iostream>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio();
  cin.tie(0);
  
  int A, B, C;
  cin >> A >> B >> C;
  cout << A + B - C << '\n';
  cout << stoi(to_string(A) + to_string(B)) - C;
}