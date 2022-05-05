#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tsp(vector<vector<int>>& dp, vector<vector<int>>& weight, int curr, int visited, int N) {
    if (visited == (1 << N) - 1) {
        if (!weight[curr][0]) {
            return 1e9;
        }
        return weight[curr][0];
    }
    if (dp[visited][curr] != 1e9) {
        return dp[visited][curr];
    }
    for (int i = 0; i < N; i++) {
        if (!(visited & (1 << i)) && weight[curr][i]) {
            dp[visited][curr] = min(dp[visited][curr], tsp(dp, weight, i, visited | (1 << i), N) + weight[curr][i]);
        }
    }
    return dp[visited][curr];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<vector<int>> weight(N, vector<int>(N, 0));
    vector<vector<int>> dp(1 << N, vector<int>(N, 1e9));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> weight[i][j];
        }
    }
    cout << tsp(dp, weight, 0, 1, N);
    return 0;
}