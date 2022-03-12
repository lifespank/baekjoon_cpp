#include <cstdio>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isInBoard(int x, int y, int r, int c) {
    return x >= 0 && x < r && y >= 0 && y < c;
}

void waterSpread(vector<vector<int>> &waterMap, vector<vector<char>> &board, queue<pair<int, int>> &waterSource, int r, int c) {
    queue<pair<int, int>> waterQueue;
    while (!waterSource.empty()) {
        pair<int, int> water = waterSource.front();
        waterSource.pop();
        waterMap[water.first][water.second] = 0;
        waterQueue.push(water);
    }
    while (!waterQueue.empty()) {
        int hereX = waterQueue.front().first;
        int hereY = waterQueue.front().second;
        waterQueue.pop();
        for (int i = 0; i < 4; i++) {
            int nX = hereX + dx[i];
            int nY = hereY + dy[i];
            if (isInBoard(nX, nY, r, c) && board[nX][nY] == '.' && waterMap[nX][nY] == INT_MAX) {
                waterQueue.push({nX, nY});
                waterMap[nX][nY] = waterMap[hereX][hereY] + 1;
            }
        }
    }
}

int bfs(vector<vector<char>> &board, vector<vector<int>> &waterMap, pair<int, int> hedgehog, int r, int c) {
    vector<vector<int>> depth(r, vector<int>(c, -1));
    queue<pair<int, int>> queue;
    queue.push(hedgehog);
    depth[hedgehog.first][hedgehog.second] = 0;
    while (!queue.empty()) {
        int hereX = queue.front().first;
        int hereY = queue.front().second;
        int hereDepth = depth[hereX][hereY];
        queue.pop();
        if (board[hereX][hereY] == 'D') {
            return depth[hereX][hereY];
        }
        for (int i = 0; i < 4; i++) {
            int nX = hereX + dx[i];
            int nY = hereY + dy[i];
            if (isInBoard(nX, nY, r, c) && hereDepth + 1 < waterMap[nX][nY] && (board[nX][nY] == '.' || board[nX][nY] == 'D') && depth[nX][nY] == -1) {
                queue.push({nX, nY});
                depth[nX][nY] = hereDepth + 1;
            }
        }
    }
    return -1;
}

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    getchar();
    vector<vector<char>> board(r, vector<char>(c, 0));
    vector<vector<int>> waterMap(r, vector<int>(c, INT_MAX));
    pair<int, int> hedgehog;
    queue<pair<int, int>> waterSource;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            board[i][j] = getchar();
            if (board[i][j] == 'S') {
                hedgehog = {i, j};
                board[i][j] = '.';
            } else if (board[i][j] == '*') {
                waterSource.push({i, j});
            }
        }
        getchar();
    }
    waterSpread(waterMap, board, waterSource, r, c);
    int ans = bfs(board, waterMap, hedgehog, r, c);
    if (ans == -1) {
        printf("KAKTUS");
    } else {
        printf("%d", ans);
    }
    return 0;
}