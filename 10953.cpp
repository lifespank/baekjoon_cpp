#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int T;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for(int i = 0; i < T; i++) {
        int a, b;
        char comma;
        cin >> a >> comma >> b;
        cout << a + b << '\n';
    }
    return 0;
}