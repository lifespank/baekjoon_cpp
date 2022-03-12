#include <iostream>
#include <bits/stdc++.h>
#include <memory.h>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        if(tc == 3) {
            cout << "";
        }
        int N, M, dp[10001];
        memset(dp, 0, sizeof(dp));
        vector<int> coins;
        cin >> N;
        for(int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            coins.push_back(tmp);
        }
        cin >> M;
        for(int i = 0; i <= M; i++) {
            if(!(i % coins[0])) {
                dp[i] = 1;
            }
        }
        for(int i = 1; i < coins.size(); i++) {
            for(int j = coins[i]; j <= M; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        cout << dp[M] << "\n";
    }
    return 0;
}