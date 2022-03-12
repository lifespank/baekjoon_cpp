#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string multiply(string num1, string num2) {
    int len1 = num1.length();
    int len2 = num2.length();
    vector<int> result(len1 + len2, 0);
    int n1Idx = 0;
    int n2Idx = 0;
    for (int i = len1 - 1; i >= 0; i--) {
        int carry = 0;
        int n1 = num1[i] - '0';
        n2Idx = 0;
        for (int j = len2 - 1; j >= 0; j--) {
            int n2 = num2[j] - '0';
            int sum = n1 * n2 + result[n1Idx + n2Idx] + carry;
            carry = sum / 10;
            result[n1Idx + n2Idx] = sum % 10;
            n2Idx++;
        }
        if (carry > 0) {
            result[n1Idx + n2Idx] += carry;
        }
        n1Idx++;
    }
    int idx = result.size() - 1;
    while (idx >= 0 && result[idx] == 0) {
        idx--;
    }
    if (idx == -1) {
        return "0";
    }
    string ans = "";
    for ( ; idx >= 0; idx--) {
        ans += to_string(result[idx]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    cout << multiply(a, b);
    return 0;
}