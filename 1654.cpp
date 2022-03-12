#include <iostream>
#include <algorithm>

using namespace std;

bool lanIsGood(int n, int len, long long *lans, int k) {
    long long total = 0;
    for (int i = 0; i < k; i++) {
        total += lans[i] / len;
    }
    return total >= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, n;
    cin >> k >> n;
    long long *lans = new long long[k];
    for (int i = 0; i < k; i++) {
        cin >> lans[i];
    }
    long long low = 1;
    long long high = *max_element(lans, lans + k);
    long long ans = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (lanIsGood(n, mid, lans, k)) {
            ans = max(ans, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans;
    delete[] lans;
    return 0;
}