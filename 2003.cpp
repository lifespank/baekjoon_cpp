#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int start = 0;
    int end = 0;
    int sum = a[0];
    int count = 0;
    while (end < N) {
        if (sum < M) {
            sum += a[++end];
        } else if (sum == M) {
            count++;
            sum -= a[start++];
            sum += a[++end];
        } else {
            sum -= a[start++];
            if (start > end) {
                end = start;
                sum = a[start];
            }
        }
    }
    cout << count;
    return 0;
}