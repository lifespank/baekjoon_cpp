#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkRouterDistance(int c, vector<int> &coords, int distance) {
    int lastPos = 0;
    int count = 1;
    for (int i = 1; i < coords.size(); i++) {
        if (coords[i] - coords[lastPos] >= distance) {
            lastPos = i;
            count++;
        }
    }
    if (count >= c) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, c;
    cin >> n >> c;
    vector<int> coords(n);
    for (int i = 0; i < n; i++) {
        cin >> coords[i];
    }
    sort(coords.begin(), coords.end());
    int low = 1;
    int high = coords[n - 1] - coords[0];
    int ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (checkRouterDistance(c, coords, mid)) {
            ans = max(ans, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans;
    return 0;
}