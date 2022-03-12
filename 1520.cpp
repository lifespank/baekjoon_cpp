#include <iostream>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

int M, N;
int board[500][500];
int dp[500][500];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool isInBoard(int x, int y) {
    return x >= 0 && x < M && y >= 0 && y < N;
}


int calc(int x, int y) {
    if(dp[x][y] != -1) {
        return dp[x][y];
    }
    dp[x][y] = 0;
    for(int i = 0; i < 4; i++) {
        int nX = x + dx[i];
        int nY = y + dy[i];
        if(isInBoard(nX, nY) && board[nX][nY] > board[x][y]) {
            dp[x][y] += calc(nX, nY);
        }
    }
    return dp[x][y];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 1;
    int a, b;
    cout << calc(M - 1, N - 1);
    return 0;
}