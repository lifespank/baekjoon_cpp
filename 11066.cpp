#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
#include <memory.h>

using namespace std;

int files[500];
int dp[500][500];
int sum[500];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, K;
    cin >> T;
    for(int tc = 0; tc < T; tc++) {
        memset(files, 0, sizeof(files));
        memset(sum, 0, sizeof(sum));
        memset(dp, 0, sizeof(dp));
        cin >> K;
        for(int i = 0; i < K; i++) {
            cin >> files[i];
            if(i > 0) {
                sum[i] = files[i] + sum[i - 1];
            }
            else {
                sum[i] = files[i];
            }
        }
        for(int d = 1; d < K; d++) {
            for(int tx = 0; tx + d < K; tx++) {
                int ty = tx + d;
                dp[tx][ty] = 1e9;
                for(int mid = tx; mid < ty; mid++) {
                    dp[tx][ty] = min(dp[tx][ty], dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - (tx > 0 ? sum[tx - 1] : 0));
                }
            }
        }

        cout << dp[0][K - 1] << '\n';
    }


    return 0;
}