#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int arr[10000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, i, j, one;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> one;
        arr[one - 1]++;
    }
    for(i = 0; i < 10000; i++) {
        for(j = 0; j < arr[i]; j++) {
            cout << i + 1 << "\n";
        }
    }
    return 0;
}
