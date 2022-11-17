#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int maxVal;

void comb(int stage, int sum, vector<int>& W) {
    if (stage == N - 1) {
        maxVal = max(maxVal, sum);
        return;
    }
    for (int i = 1; i < W.size() - 1; i++) {
        int score = W[i - 1] * W[i + 1];
        int temp = W[i];
        W.erase(W.begin() + i);
        comb(stage + 1, sum + score, W);
        W.insert(W.begin() + i, temp); 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    vector<int> W(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }
    comb(1, 0, W);
    cout << maxVal;
    return 0;
}