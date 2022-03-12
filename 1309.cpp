#include <iostream>
#include <bits/stdc++.h>
#define PRIME 9901

using namespace std;

int N;
int dp[100001][3];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    for(int i = 2; i <= N; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % PRIME;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % PRIME;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % PRIME;
    }
    int ans = 0;
    for(int i = 0; i < 3; i++) {
        ans = (ans + dp[N][i]) % PRIME;
    }
    cout << ans;

    return 0;
}