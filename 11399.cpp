#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int sum = v[0];
    for(int i = 1; i < N; i++) {
        v[i] += v[i - 1];
        sum += v[i];
    }
    cout << sum;
    return 0;
}