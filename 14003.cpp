#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> lis;
    vector<int> indices(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (lis.empty()) {
            lis.push_back(arr[i]);
            indices[i] = lis.size() - 1;
        } else if (lis.back() < arr[i]) {
            lis.push_back(arr[i]);
            indices[i] = lis.size() - 1;
        } else {
            auto lower_bound_it = lower_bound(lis.begin(), lis.end(), arr[i]);
            *lower_bound_it = arr[i];
            indices[i] = lower_bound_it - lis.begin();
        }
    }
    cout << lis.size() << '\n';
    vector<int> ans;
    int idx = lis.size() - 1;
    for (int i = N - 1; i >= 0; i--) {
        if (idx == indices[i]) {
            ans.push_back(arr[i]);
            idx--;
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }
    return 0;
}