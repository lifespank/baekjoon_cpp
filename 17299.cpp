#include <iostream>
#include <bits/stdc++.h>
#include <stack>
#include <vector>

using namespace std;

int freq[1000001];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> arr;
    vector<int> ans(N, -1);
    stack<int> stk;
    for(int i = 0; i < N; i++) {
        int dummy;
        cin >> dummy;
        arr.push_back(dummy);
        freq[dummy]++;
    }
    for(int i = 0; i < N; i++) {
        while(!stk.empty() && freq[arr[stk.top()]] < freq[arr[i]]) {
            ans[stk.top()] = arr[i];
            stk.pop();
        }
        stk.push(i);
    }

    for(auto i : ans) {
        cout << i << ' ';
    }

    return 0;
}