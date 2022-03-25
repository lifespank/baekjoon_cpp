#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;
    vector<vector<vector<int>>> lcs(str1.length() + 1, vector<vector<int>>(str2.length() + 1, vector<int>(str3.length() + 1, 0)));
    for (int i = 1; i <= str1.length(); i++) {
        for (int j = 1; j <= str2.length(); j++) {
            for (int k = 1; k <= str3.length(); k++) {
                if (str1[i - 1] == str2[j - 1] && str2[j - 1] == str3[k - 1]) {
                    lcs[i][j][k] = lcs[i - 1][j - 1][k - 1] + 1;
                } else {
                    lcs[i][j][k] = max(lcs[i - 1][j][k], max(lcs[i][j - 1][k], lcs[i][j][k - 1]));
                }
            }
        }
    }
    cout << lcs[str1.length()][str2.length()][str3.length()];
    return 0;
}