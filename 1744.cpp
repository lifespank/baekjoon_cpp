#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N;
deque<int> nums;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    int sum = 0;
    sort(nums.begin(), nums.end());
    
    cout << sum;

    return 0;
}