#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int depth;

long long decNum(int start, int N) {
    queue<long long> q;
    q.push(start);
    while(!q.empty()) {
        long long here = q.front();
        q.pop();
        if(depth == N) {
            return here;
        }
        if(here > 9876543210) {
            return -1;
        }
        int LSN = here % 10;
        int sLSN = here >= 10 ? (here / 10) % 10 : 10;
        if(LSN == 0) {
            for(int i = 1; i < sLSN; i++) {
                depth++;
                if(depth == N) {
                    return here + i;
                }
            }
        }
        if(LSN == 0) {
            depth++;
            for(int i = 1; i < sLSN; i++) {
                if(depth <= N) {
                    q.push((here + i) * 10);
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    cout << decNum(0, N);

    return 0;
}