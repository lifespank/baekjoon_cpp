#include <iostream>
#include <algorithm>

using namespace std;

bool isKth(int k, int num, int n) {
     int count = 0;
     for (int i = 1; i <= n; i++) {
         count += min(num / i, n);
     }
     return count < k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int low = 1;
    int high = k;
    int ans = 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isKth(k, mid, n)) {
            low = mid + 1;
        } else {
            high = mid - 1;
            ans = mid;
        }
    }
    cout << ans;
    return 0;
}