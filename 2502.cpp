#include <iostream>
#include <bits/stdc++.h>
#include <memory.h>

using namespace std;

int dp[31];

int coEff(int n) {
    if(dp[n] != -1) {
        return dp[n];
    }
    dp[n] = coEff(n - 1) + coEff(n - 2);
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;
    int D, K;
    cin >> D >> K;
    int coEffA = coEff(D);
    int coEffB = coEff(D + 1);
    int i, j;
    for(i = 1; i < K; i++) {
        for(j = i; j < K; j++) {
            if(i * coEffA + j * coEffB == K) {
                break;
            }
        }
        if(j < K - 1) {
            break;
        }
    }
    cout << i << '\n' << j;

    return 0;
}