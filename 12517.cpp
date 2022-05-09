#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    string country;
    string ruledBy;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> country;
        switch (country[country.length() - 1]) {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
            ruledBy = "a queen";
            break;
            case 'y':
            case 'Y':
            ruledBy = "nobody";
            break;
            default:
            ruledBy = "a king";
            break;
        }
        cout << "Case #" << tc << ": " << country << " is ruled by " << ruledBy << ".\n";
    }
    return 0;
}