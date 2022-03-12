#include <iostream>

using namespace std;

int sum(int n) {
    return n * (n + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << sum(n / 2 - 1) + sum(n - n / 2 - 1);
    return 0;
}