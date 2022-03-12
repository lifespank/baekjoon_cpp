#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str) {
    for (int i = 0; i < str.size() / 2; i++) {
        if (str[i] != str[str.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    cin >> str;
    if (isPalindrome(str)) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}