#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <memory.h>

using namespace std;

int n;
int board[500][500];
int dp[500][500];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool isInBoard(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int dfs(int x, int y) {
    if(dp[x][y]) {
        return dp[x][y];
    }
    dp[x][y] = 1;
    for(int i = 0; i < 4; i++) {
        int nX = x + dx[i];
        int nY = y + dy[i];
        if(isInBoard(nX, nY) && board[nX][nY] > board[x][y]) {
            dp[x][y] = max(dp[x][y], dfs(nX, nY) + 1);
        }
    }
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    int maxLive = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            maxLive = max(maxLive, dfs(i, j));
        }
    }
    cout << maxLive;
    return 0;
}