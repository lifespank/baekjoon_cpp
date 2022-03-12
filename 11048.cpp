#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getVal(int i, int j, int n, int m, vector<vector<int>>& board) {
    if (i >= 0 && i < n && j >= 0 && j < m) {
        return board[i][j];
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            board[i][j] = temp + max({getVal(i - 1, j, n, m, board), getVal(i, j - 1, n, m, board), getVal(i - 1, j - 1, n, m, board)});
        }
    }
    cout << board[n - 1][m - 1];
    return 0;
}