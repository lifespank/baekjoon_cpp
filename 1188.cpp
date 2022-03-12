#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> M >> N;
    int cut;
    if(N == M) {
        cut = 0;
    }
    else if(N > M) {
        cut = N / M;
        if(N % M == 0) {
            cut--;
        }
        cut *= M;
    }
    else {
        int g = gcd(N , M);
        N /= g;
        cut = N - 1;
    }
    cout << cut;
    return 0;
}