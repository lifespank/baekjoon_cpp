#include <iostream>
#include <string>

using namespace std;

int N;

pair<bool, int> isIn(int n) {
    int i = 1;
    while(n > 0) {
        n -= i;
        i++;
    }
    if(n == 0) {
        return {true, i - 1};
    }
    else {
        return {false, 0};
    }
}

int main() {
    cin >> N;
    string ans = "";
    pair<bool, int> tmp = isIn(N);
    if(tmp.first) {
        for(int i = 0; i < tmp.second; i++) {
            ans += i + 'A';
        }
        for(int i = 1; i < tmp.second; i++) {
            for(int j = 0; j < i; j++) {
                ans += i + 'A';
            }
        }
    }
    else {
        ans = "-1";
    }
    cout << ans;
    return 0;
}