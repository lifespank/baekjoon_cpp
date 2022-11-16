#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isGood(vector<char>& braces, vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        if (braces[i - 1] == '<' && nums[i - 1] > nums[i] || braces[i - 1] == '>' && nums[i - 1] < nums[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int k;
    cin >> k;
    vector<char> braces(k);
    for (int i = 0; i < k; i++) {
        cin >> braces[i];
    }
    vector<int> small(k + 1);
    vector<int> big(k + 1);
    for (int i = 0; i <= k; i++) {
        small[i] = i;
        big[i] = 9 - i;
    }
    do {
        if (isGood(braces, small)) {
            break;
        }
    } while (next_permutation(small.begin(), small.end()));
    do {
        if (isGood(braces, big)) {
            break;
        }
    } while (prev_permutation(big.begin(), big.end()));
    for (int i = 0; i < big.size(); i++) {
        cout << big[i];
    }
    cout << '\n';
    for (int i = 0; i < small.size(); i++) {
        cout << small[i];
    }
    return 0;
}