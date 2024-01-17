#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    // 시작지점 맨 왼쪽 위
    int x{1}, y{1};
    int n, k, a, b, L, timer{0}, dir{0};
    char t;
    queue<pair<int, char>> v;

    // 동 서 남 북
    // 오른쪽, 아래쪽, 왼쪽, 위쪽
    // 0  1 2  3
    vector<int> dx{1, 0, -1, 0};
    vector<int> dy{0, 1, 0, -1};
    queue<pair<int, int>> now;
    
    cin >> n >> k;

    // 0으로 초기화
    vector<vector<int>> map(n+1, vector<int>(n+1, 0));
    // 뱀이 있으면 2로 초기화
    map[1][1] = 2;
    now.push({1, 1});
    // 사과가 있으면 1로 초기화
    for (auto i = 0; i < k; i++) {
        cin >> a >> b;
        map[a][b] = 1;
    }

    cin >> L;
    for (auto i = 0; i < L; i++) {
        cin >> a >> t;
        v.push({a, t});
    }

    while(true) {
        timer += 1; // 시간 추가
        x += dx[dir];
        y += dy[dir];

        // 벽에 부딪히면 종료
        if (x > n || y > n || x < 1 || y < 1) break;
        // 자신의 몸이면 종료
        if (map[y][x] == 2) break;
        // 사과가 없을 때
        if (map[y][x] != 1) { 
            int tmpy = now.front().first;
            int tmpx = now.front().second;
            map[tmpy][tmpx] = 0; // 꼬리 삭제
            now.pop();
        }
        map[y][x] = 2; // 현재 위치에 뱀 몸통 표시   
        now.push({y, x}); // 새로운 위치 추가

        // 방향 전환
        if(timer == v.front().first) {
            if (v.front().second == 'D') { // 오른쪽
                dir = (dir + 1) % 4;
            } else { // 왼쪽
                dir = (dir + 3) % 4;
            }
            v.pop();
        }
    }
    cout << timer << endl;
}