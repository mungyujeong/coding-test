#include<iostream>
#include <algorithm>

#define MAX_N 100

using namespace std;

int n;
int arr[MAX_N];

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	//cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n;
        for (int i = 0; i < MAX_N; i++) {
            cin >> arr[i];
        }       
        
        bool is_finish = true;
        while(n--) {
            
            int max_idx = max_element(arr, arr + MAX_N) - arr;
            int min_idx = min_element(arr, arr + MAX_N) - arr;
            int diff = arr[max_idx] - arr[min_idx];

            if (diff == 0 || diff == 1) {
                cout << "#" << test_case << " " << diff << '\n';
                is_finish = false;
                break;
            }

            arr[max_idx] -= 1;
            arr[min_idx] += 1;
        }

        if(is_finish) {
            int max_idx = max_element(arr, arr + MAX_N) - arr;
            int min_idx = min_element(arr, arr + MAX_N) - arr;
            int diff = arr[max_idx] - arr[min_idx];
            cout << "#" << test_case << " " << diff << '\n';
        }
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}