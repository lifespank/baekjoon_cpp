#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ballOutMax = 0;

bool isInBoard(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(vector<vector<int>> &board, vector<vector<int>> &dp, int x, int y, int depth) {
    dp[x][y] = max(dp[x][y], depth);
    int maxVal = 0;
    for (int i = 0; i < 4; i++) {
        int nX = x + dx[i] * board[x][y];
        int nY = y + dy[i] * board[x][y];
        if (!isInBoard(nX, nY, board.size(), board[0].size())) {
            ballOutMax = max(ballOutMax, depth + 1);
        } else if (board[nX][nY] == 'H' - '0') {
            dp[nX][nY] = max(dp[nX][nY], depth + 1);
        } else if (dp[nX][nY] < depth + 1){
            dfs(board, dp, nX, nY, depth + 1);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();
    vector<vector<int>> board(n, vector<int>(m, 0));
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = getchar() - '0';
        }
        getchar();
    }
    dfs(board, dp, 0, 0, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'H' - '0') {
                ans = max(ans, dp[i][j]);
            } else if (dp[i][j] == INF) {
                ans = max(ans, INF);
            }
        }
    }
    ans = max(ans, ballOutMax);
    if (ans == INF) {
        ans = -1;
    }
    printf("%d", ans);
    return 0;
}