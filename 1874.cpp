#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    stack<int> stk;
    vector<char> ans;
    cin >> n;
    int curr = 1;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        while (curr <= num) {
            stk.push(curr);
            curr++;
            ans.push_back('+');
        }
        if (!stk.empty() && stk.top() == num) {
            stk.pop();
            ans.push_back('-');
        } else {
            cout << "NO";
            return 0;
        }
    }
    for (auto &ch : ans) {
        cout << ch << '\n';
    }
    return 0;
}