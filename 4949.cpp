#include <iostream>
#include <bits/stdc++.h>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> stk;
    string s;
    getline(cin, s);
    while(s != ".") {
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                stk.push(s[i]);
            }
            else if(s[i] == '[') {
                stk.push(s[i]);
            }
            else if(s[i] == ')') {
                if(stk.empty()) {
                    stk.push(s[i]);
                }
                else if(stk.top() == '(') {
                    stk.pop();
                }
                else {
                    stk.push(s[i]);
                }
            }
            else if(s[i] == ']') {
                if(stk.empty()) {
                    stk.push(s[i]);
                }
                else if(stk.top() == '[') {
                    stk.pop();
                }
                else {
                    stk.push(s[i]);
                }
            }
        }
        if(stk.empty()) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
        while(!stk.empty()) {
            stk.pop();
        }
        getline(cin, s);
    }
    

    return 0;
}