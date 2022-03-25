#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string line;
    string ucpc = "UCPC";
    getline(cin, line);
    int idx = 0;
    for (auto &ch : line) {
        if (ucpc[idx] == ch) {
            idx++;
        }
        if (idx == 4) {
            break;
        }
    }
    if (idx == 4) {
        cout << "I love UCPC";
    } else {
        cout << "I hate UCPC";
    }
    return 0;
}