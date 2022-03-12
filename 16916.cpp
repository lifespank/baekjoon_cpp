#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str1, str2;
    cin >> str1 >> str2;
    if (str1.find(str2) != string::npos) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}