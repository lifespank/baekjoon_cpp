#include <iostream>
#include <bits/stdc++.h>
#define MOD 1000000000

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, 0));
    for (int i = 0; i <= n; i++) {
        dp[1][i] = 1;
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            for (int l = 0; l <= j; l++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % MOD;
            }
        }
    }
    cout << dp[k][n];
    return 0;
}