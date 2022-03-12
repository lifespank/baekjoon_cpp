#include <iostream>
#include <string>

using namespace std;

int main() {
    string ans = "";
    char c;
    c = getchar();
    while(c != '\n') {
        int xCount = 0;
        while(c == 'X') {
            xCount++;
            if(xCount == 4) {
                ans += "AAAA";
                xCount = 0;
            }
            c = getchar();
        }
        if(xCount == 2) {
            ans += "BB";
            xCount = 0;
        }
        else if(xCount != 0){
            ans = "-1";
            break;
        }
        if(c == '.') {
            ans += ".";
            c = getchar();
        }
    }
    cout << ans;
    return 0;
}