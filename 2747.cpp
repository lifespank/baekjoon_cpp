#include <iostream>
#include <cstring>
using namespace std;

int dp[46];
int n;

int fib(int n) {
    if(dp[n] != -1) {
        return dp[n];
    }
    dp[n] = fib(n - 2) + fib(n - 1);
    return dp[n];
}

int main() {
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    cin >> n;
    cout << fib(n);
    return 0;
}