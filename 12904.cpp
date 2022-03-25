#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string S, T;
    cin >> S >> T;
    while (S.length() < T.length()) {
        if (T.back() == 'A') {
            T.pop_back();
        } else {
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }
    if (S == T) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}