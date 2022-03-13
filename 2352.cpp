#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int my_lower_bound(vector<int> &arr, int start, int end, int val) {
    int low = start;
    int high = end;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= val) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return high;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> lis;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (lis.empty()) {
            lis.push_back(arr[i]);
        } else if (lis.back() < arr[i]) {
            lis.push_back(arr[i]);
        } else {
            lis[my_lower_bound(lis, 0, lis.size() - 1, arr[i])] = arr[i];
        }
    }
    cout << lis.size();
    return 0;
}