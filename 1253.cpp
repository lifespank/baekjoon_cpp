#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N;
int nums[2000];
unordered_map<int, bool> selected;



int main() {
    cin >> N;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + N);
    for(int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            if(binary_search(nums, nums + N, nums[i] + nums[j]) && selected.find(nums[i] + nums[j]) == selected.end()) {
                selected.insert({nums[i] + nums[j], true});
                for(int k = 0; k < N; k++) {
                    if(nums[k] == nums[i] + nums[j]) {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}