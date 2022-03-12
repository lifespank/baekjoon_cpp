#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int board[1000][1000];
int dp[1000][1000];

int calc(int x, int y) {
	if (dp[x][y] != -1) {
		return dp[x][y];
	}
	else {
		if (board[x][y] == 0) {
			dp[x][y] = 0;
		}
		else if (x == 0 || y == 0) {
			dp[x][y] = 1;
		}
		else {
			dp[x][y] = min({ calc(x - 1, y), calc(x, y - 1), calc(x - 1, y - 1) }) + 1;
		}
		return dp[x][y];
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	memset(board, 0, sizeof(int) * n * m);
	for (int i = 0; i < n; i++) {
		fill(dp[i], dp[i] + m, -1);
		string line;
		cin >> line;
		for (int j = 0; j < m; j++) {
			board[i][j] = (int)line[j] - '0';
		}
	}
	int maxEl = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			calc(i, j);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			maxEl = max(maxEl, dp[i][j]);
		}
	}
	cout << maxEl * maxEl;
	return 0;
}