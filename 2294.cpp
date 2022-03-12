#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> coins(n, 0);
    vector<int> dp(k + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    for (int i = 1; i <= k; i++) {
        int minVal = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] >= 0) {
                minVal = min(minVal, dp[i - coins[j]]);
            }
        }
        if (minVal != INT_MAX) {
            dp[i] = minVal + 1;
        }
    }
    cout << dp[k];
    return 0;
}