#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str1, str2;
    cin >> str1 >> str2;
    vector<vector<int>> dp(str1.size(), vector<int>(str2.size()));
    int maxVal = 0;
    for (int i = 0; i < str1.size(); i++) {
        for (int j = 0; j < str2.size(); j++) {
            if (i == 0 || j == 0) {
                if (str1[i] == str2[j]) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
            } else if (str1[i] == str2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = 0;
            }
            maxVal = max(maxVal, dp[i][j]);
        }
    }
    cout << maxVal;
    return 0;
}