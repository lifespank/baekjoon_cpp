#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

long long binarySearch(long long l, long long r, long long n) {
    if(r >= l) {
        long long mid = l + (r - l) / 2;
        if(mid  == sqrtl(n)) {
            return mid;
        }
        if(mid > sqrtl(n)) {
            return binarySearch(l, mid - 1, n);
        }
        return binarySearch(mid + 1, r, n);
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    cout << binarySearch(0, n, n);

    return 0;
}