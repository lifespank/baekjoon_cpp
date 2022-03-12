#include <iostream>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

int K;
stack<int> stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> K;
    int sum = 0;
    for(int i = 0; i < K; i++) {
        int tmp;
        cin >> tmp;
        if(tmp != 0) {
            stk.push(tmp);
        }
        else {
            stk.pop();
        }
    }
    while(!stk.empty()) {
        sum += stk.top();
        stk.pop();
    }
    cout << sum;
    return 0;
}