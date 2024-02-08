#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 128

using namespace std;

int n; 
char lc[MAX_N], rc[MAX_N];

void preorder(char cur) {
    cout << cur;
    if (lc[cur] != '.') preorder(lc[cur]);
    if (rc[cur] != '.') preorder(rc[cur]);
}

void inorder(char cur) {
    if (lc[cur] != '.') inorder(lc[cur]);
    cout << cur;
    if (rc[cur] != '.') inorder(rc[cur]);
}

void postorder(char cur) {
    if (lc[cur] != '.') postorder(lc[cur]);
    if (rc[cur] != '.') postorder(rc[cur]);
    cout << cur;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        char p, l, r;
        cin >> p >> l >> r;
        lc[p] = l;
        rc[p] = r;
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
}