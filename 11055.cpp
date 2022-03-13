#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> lis(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        int maxVal = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                maxVal = max(maxVal, lis[j]);
            }
        }
        lis[i] = maxVal + 1;
    }
    cout << *max_element(lis.begin(), lis.end());
    return 0;
}