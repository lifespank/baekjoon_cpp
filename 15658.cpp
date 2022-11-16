#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1000000000;
int i;
int N;
int nums[11];
int operators[4];
int maxRes = -MAX;
int minRes = MAX;

void DFS(int plus, int minus, int times, int divides, int idx, int sum);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> nums[i];
	}
	for (i = 0; i < 4; i++) {
		cin >> operators[i];
	}
	DFS(operators[0], operators[1], operators[2], operators[3], 1, nums[0]);
	cout << maxRes << "\n" << minRes;
	return 0;
}

void DFS(int plus, int minus, int times, int divides, int idx, int sum) {
	if (idx == N) {
		maxRes = max(sum, maxRes);
		minRes = min(sum, minRes);
        return;
	}

	if (plus > 0) {
		DFS(plus - 1, minus, times, divides, idx + 1, sum + nums[idx]);
	}
	if (minus > 0) {
		DFS(plus, minus - 1, times, divides, idx + 1, sum - nums[idx]);
	}
	if (times > 0) {
		DFS(plus, minus, times - 1, divides, idx + 1, sum * nums[idx]);
	}
	if (divides > 0) {
		DFS(plus, minus, times, divides - 1, idx + 1, sum / nums[idx]);
	}

}