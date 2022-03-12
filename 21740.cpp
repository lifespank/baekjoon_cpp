#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<string> nums;

char flipOne(char num) {
    if(num == '6') {
        return '9';
    }
    else if(num == '9') {
        return '6';
    }
    else {
        return num;
    }
}

string flip(string num) {
    reverse(num.begin(), num.end());
    for(int i = 0; i < num.size(); i++) {
        num[i] = flipOne(num[i]);
    }
    return num;
}




int main() {
    cin >> N;
    string ans = "";
    int maxSize = 0;
    for(int i = 0; i < N; i++) {
        string input;
        cin >> input;
        nums.push_back(flip(input));
        maxSize = max(maxSize, (int)input.size());
    }
    sort(nums.begin(), nums.end(), greater<string>());
    bool twice = false;
    for(int i = 0; i < nums.size(); i++) {
        ans += nums[i];
        if(!twice && nums[i].size() == maxSize) {
            ans += nums[i];
            twice = true;
        }
    }
    ans = flip(ans);

    cout << ans;
    return 0;
}