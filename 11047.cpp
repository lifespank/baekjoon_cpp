#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int count = 0;
    for (int i = n - 1; i >= 0 && k > 0; i--) {
        count += k / coins[i];
        k %= coins[i];
    }
    cout << count;
    return 0;
}