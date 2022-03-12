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
    vector<vector<int>> dp(str1.length() + 1, vector<int>(str2.length() + 1, 0));
    for (int i = 1; i <= str1.length(); i++) {
        for (int j = 1; j <= str2.length(); j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string ans;
    int i = str1.length();
    int j = str2.length();
    while (i > 0 && j > 0) {
        if (dp[i - 1][j] == dp[i][j]) {
            i--;
        } else if (dp[i][j - 1] == dp[i][j]) {
            j--;
        } else {
            ans += str1[i - 1];
            i--;
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.length() << "\n" << ans;
    return 0;
}