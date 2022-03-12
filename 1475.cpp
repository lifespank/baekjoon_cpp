#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[10] = {0};
    int n;
    cin >> n;
    while(n > 0) {
        arr[n % 10]++;
        n /= 10;
    }
    int maxVal = 0;
    for(int i = 0; i < 10; i++) {
        if (i != 6 && i != 9) {
            maxVal = max(arr[i], maxVal);
        }
    }

    cout << max(maxVal, (arr[6] + arr[9] + 1) / 2);

    return 0;
}