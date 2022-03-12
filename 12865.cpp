#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int N, K;
int V[101], W[101];
int dp[101][100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= K; j++) {
            if(j >= W[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[N][K];
    return 0;
}