#include <iostream>
#include <deque>

using namespace std;

int test_case;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> test_case;

    while (test_case--) {
        string p;
        int n;
        string numbers;
        deque<int> DQ;
        deque<int> RDQ;

        cin >> p;
        cin >> n;
        cin >> numbers;

        string tmp;
        for (auto s : numbers){
            if ('0' <= s && s <= '9')
                tmp += s;
            else if (s == ',' || s == ']') {
                if (tmp.empty()) break;
                DQ.push_back(stoi(tmp));
                // cout << tmp << endl;
                tmp.clear();
            }
        }
        
        bool is_error = false;
        bool is_front = true;
        for (auto c : p) {
            if (c == 'R') {
                is_front = !is_front;                
            } 
            else {
                if (DQ.empty()) {
                    cout << "error\n";
                    is_error = true;
                    break;
                }

                if (is_front) {
                    // cout << "front: " << DQ.front() << '\n';
                    DQ.pop_front();
                } else {
                    DQ.pop_back();
                }
            }
        }

        if (!is_error) {
            cout << '[';

            if (is_front) {
                while (DQ.size() > 1) {
                    cout << DQ.front() << ",";
                    DQ.pop_front();
                }
            } 
            else {
                while (DQ.size() > 1) {
                    cout << DQ.back() << ",";
                    DQ.pop_back();
                }
            }

            if (!DQ.empty()) 
                cout << DQ.front();

            cout << "]\n";
        }
    }
}