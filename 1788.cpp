#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#define BIG 1000000000

using namespace std;

int dp[1000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    int k = abs(n);
    for(int i = 2; i <= k; i++) {
        dp[i] = (dp[i - 2] + dp[i - 1]) % BIG;
    }
    if(n < 0) {
        if(k & 1) {
            cout << "1\n";
        }
        else {
            cout << "-1\n";
        }
    }
    else if(n == 0) {
        cout << "0\n";
    }
    else {
        cout << "1\n";
    }
    cout << dp[k];
    return 0;
}