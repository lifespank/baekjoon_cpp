#include <cstdio>
#include <vector>

using namespace std;

int dx[3] = {-1, 0, 1};

bool isInBoard(int x, int y, int R, int C) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

bool dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int x, int y) {
    visited[x][y] = true;
    if (y == board[0].size() - 1) {
        return true;
    }
    int nY = y + 1;
    for (int i = 0; i <3; i++) {
        int nX = x + dx[i];
        if (isInBoard(nX, nY, board.size(), board[0].size()) && !visited[nX][nY] && board[nX][nY] == '.' && dfs(board, visited, nX, nY)) {
            return true;
        }
    }
    return false;
}

int main() {
    int R, C;
    scanf("%d %d", &R, &C);
    getchar();
    vector<vector<char>> board(R, vector<char>(C));
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            board[i][j] = getchar();
        }
        getchar();
    }
    int pipeCount = 0;
    for (int i = 0; i < R; i++) {
        if (dfs(board, visited, i, 0)) {
            pipeCount++;
        }
    }
    printf("%d", pipeCount);
    return 0;
}