#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> lis;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (lis.empty()) {
            lis.push_back(arr[i]);
        } else if (lis.back() < arr[i]) {
            lis.push_back(arr[i]);
        } else {
            *lower_bound(lis.begin(), lis.end(), arr[i]) = arr[i];
        }
    }
    cout << lis.size();
    return 0;
}