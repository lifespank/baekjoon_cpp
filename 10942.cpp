#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, M, arr[2001];
bool dp[2001][2001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for(int i = 1; i <= N; i++) {
        dp[i][i] = true;
    }
    for(int i = 1; i < N; i++) {
        if(arr[i] == arr[i + 1]) {
            dp[i][i + 1] = true;
        }
    }
    for(int k = 3; k <= N; k++) {
        for(int i = 1; i <= N - k + 1; i++) {
            int j = i + k - 1;
            if(dp[i + 1][j - 1] && arr[i] == arr[j]) {
                dp[i][j] = true;
            }
        }
    }

    cin >> M;
    for(int i = 0; i < M; i++) {
        int S, E;
        cin >> S >> E;
        cout << dp[S][E] << '\n';
    }

    return 0;
}