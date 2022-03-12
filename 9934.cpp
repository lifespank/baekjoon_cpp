#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int tree[1024];
int visited[1024];


int twoPower(int k) {
    if(k == 0) {
        return 1;
    }
    if(k & 1) {
        return 2 * twoPower(k - 1);
    }
    else {
        return twoPower(k / 2) * twoPower(k / 2);
    }
}

void check(int cur, int len, int& idx) {
    if(cur * 2 <= len && !tree[cur * 2] && idx < len) {
        check(cur * 2, len, idx);
    }
    if(cur * 2 > len || tree[cur * 2] && !tree[cur] && idx < len) {
        tree[cur] = visited[idx];
        idx++;
        if(idx >= len) {
            return;
        }
    }
    if(tree[cur] && cur * 2 + 1 <= len && !tree[cur * 2 + 1] && idx < len) {
        check(cur * 2 + 1, len, idx);
    }
    if(tree[cur] && cur * 2 + 1 <= len && tree[cur * 2] && tree[cur * 2 + 1] && cur / 2 > 0 && idx < len) {
        check(cur / 2, len, idx);
    }
    if(idx >= len) {
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int K;
    cin >> K;
    int len = twoPower(K) - 1;
    for(int i = 0; i < len; i++) {
        cin >> visited[i];
    }
    int idx = 0;
    check(1, len, idx);
    for(int i = 1; i <= len; i++) {
        cout << tree[i] << ' ';
        if(i == 1 || !(i & (i + 1))) {
            cout << '\n';
        }
    }
    return 0;
}