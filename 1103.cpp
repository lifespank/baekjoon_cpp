#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isInBoard(int x, int y, int N, int M) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

bool dfs(vector<vector<int>> &board, vector<vector<bool>> &visited, vector<vector<int>> &dp, int hereX, int hereY) {
    visited[hereX][hereY] = true;
    if (!board[hereX][hereY]) {
        visited[hereX][hereY] = false;
        dp[hereX][hereY] = 0;
        return true;
    }
    int maxVal = 0;
    for (int i = 0; i < 4; i++) {
        int nX = hereX + board[hereX][hereY] * dx[i];
        int nY = hereY + board[hereX][hereY] * dy[i];
        if (isInBoard(nX, nY, board.size(), board[0].size())) {
            if (visited[nX][nY]) {
                return false;
            } else {
                if (dp[nX][nY] == -1) {
                    if (!dfs(board, visited, dp, nX, nY)) {
                        return false;
                    }
                }
                maxVal = max(maxVal, dp[nX][nY]);
            }
        }
    }
    dp[hereX][hereY] = maxVal + 1;
    visited[hereX][hereY] = false;
    return true;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    getchar();
    vector<vector<int>> board(N, vector<int>(M));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<vector<int>> dp(N, vector<int>(M, -1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            board[i][j] = getchar() - '0';
            if (board[i][j] < 1 || board[i][j] > 9) {
                board[i][j] = 0;
            }
        }
        getchar();
    }
    if (!dfs(board, visited, dp, 0, 0)) {
        printf("%d", -1);
    } else {
        printf("%d", dp[0][0]);
    }
    return 0;
}