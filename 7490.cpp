#include <iostream>
#include <vector>

using namespace std;

char operators[3] = {' ', '+', '-'};

void combination(vector<char> &op, vector<char> &realOp, vector<int> &nums, int numIdx, int N) {
    if (realOp.size() == N - 1) {
        int sum = nums[0];
        for (int i = 0; i < op.size(); i++) {
            if (op[i] == '+') {
                sum += nums[i + 1];
            } else {
                sum -= nums[i + 1];
            }
        }
        if (!sum) {
            for (int i = 1; i <= N; i++) {
                cout << i;
                if (i < N) {
                    cout << realOp[i - 1];
                }
            }
            cout << '\n';
        }
        return;
    }
    if (numIdx == N + 1) {
        return;
    }
    for (int i = 0; i < 3; i++) {
        realOp.push_back(operators[i]);
        if (i) {
            op.push_back(operators[i]);
            nums.push_back(numIdx);
            combination(op, realOp, nums, numIdx + 1, N);
            op.pop_back();
            nums.pop_back();
        } else {
            int numBack = nums.back();
            nums.back() = 10 * numBack + numIdx;
            combination(op, realOp, nums, numIdx + 1, N);
            nums.back() = numBack;
        }
        realOp.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testCase;
    cin >> testCase;
    while (testCase-- > 0) {
        int N;
        cin >> N;
        vector<char> op;
        vector<char> realOp;
        vector<int> nums;
        nums.push_back(1);
        combination(op, realOp, nums, 2, N);
        cout << '\n';
    }
    return 0;
}