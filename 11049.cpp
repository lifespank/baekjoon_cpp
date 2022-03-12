#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> matrices;
int dp[500][500];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int r, c;
        cin >> r >> c;
        matrices.push_back({r, c});
    }
    for(int i = 0; i < N - 1; i++) {
        dp[i][i + 1] = matrices[i].first * matrices[i].second * matrices[i + 1].second;
    }
    for(int d = 2; d < N; d++) {
        for(int i = 0; i < N - d; i++) {
            int j = i + d;
            dp[i][j] = 1e9;
            for(int mid = i; mid < j; mid++) {
                dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + matrices[i].first * matrices[mid].second * matrices[j].second);
            }
        }
    }
    cout << dp[0][N - 1];
    return 0;
}