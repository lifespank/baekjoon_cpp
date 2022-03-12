#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int T;

int GCD(int A, int B) {
    if(A < B) {
        swap(A, B);
    }
    if(A % B == 0) {
        return B;
    }
    else {
        return GCD(B, A % B);
    }
}

int LCM(int A, int B) {
    return A * B / GCD(A, B);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for(int i = 0; i < T; i++) {
        int A, B;
        cin >> A >> B;
        cout << LCM(A, B) << '\n';
    }
    return 0;
}