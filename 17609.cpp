#include <iostream>
#include <string>

using namespace std;

int isPalindrome(int low, int high, bool isTrimmed, string str) {
    while (low < high) {
        if (str[low] != str[high]) {
            if (!isTrimmed) {
                if (!isPalindrome(low + 1, high, true, str) || !isPalindrome(low, high - 1, true, str)) {
                    return 1;
                }
            }
            return 2;
        }
        low++;
        high--;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T-- > 0) {
        string str;
        cin >> str;
        int low = 0;
        int high = str.length() - 1;
        cout << isPalindrome(low, high, false, str) << '\n';
    }
    return 0;
}