#include <iostream>
#include <vector>
#include <bits/stdc++.h>
 
 using namespace std;

int N;

int CeilIndex(vector<int>& v, int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] >= key) {
            r = m;
        }
        else {
            l = m;
        }
    }
 
    return r;
}
 
int LIS(vector<int>& v) {

 
    vector<int> tail(v.size(), 0);
    int length = 1;
 
    tail[0] = v[0];
    for (int i = 1; i < v.size(); i++) {
         if (v[i] < tail[0]) {
            tail[0] = v[i];
         }
        else if (v[i] > tail[length - 1]) {
            tail[length++] = v[i];
        }
        else {
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
        }
    }
 
    return length;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    cout << LIS(v);

    return 0;
}