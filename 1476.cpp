#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int E, S, M;
    cin >> E >> S >> M;
    int year = 1;
    int e = 1;
    int s = 1;
    int m = 1;
    while(e != E || s != S || m != M) {
        e++;
        s++;
        m++;
        year++;
        if (e == 16) {
            e = 1;
        }
        if (s == 29) {
            s = 1;
        }
        if (m == 20) {
            m = 1;
        }
    }
    cout << year;
    return 0;
}