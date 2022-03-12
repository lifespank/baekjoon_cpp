#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <stack>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> stk;
    cin >> N;
    vector<int> ans(N, -1);
    vector<int> v;
    for(int i = 0; i < N; i++) {
        int dummy;
        cin >> dummy;
        v.push_back(dummy);
    }
    for(int i = 0; i < N; i++) {
        while(!stk.empty() && v[stk.top()] < v[i]) {
            ans[stk.top()] = v[i];
            stk.pop();
        }
        stk.push(i);
    }
    for(auto it = ans.begin(); it != ans.end(); it++) {
        cout << *it << " ";
    }

    
    return 0;
}