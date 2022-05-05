#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#define INF 1e9

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isInBoard(int x, int y, int w, int h) {
    return x >= 0 && x < h && y >= 0 && y < w;
}

int bfs(vector<vector<char>>& board, int startX, int startY, int dirtyCount) {
    queue<tuple<int, int, int>> q;
    vector<vector<vector<int>>> depth(board.size(), vector<vector<int>>(board[0].size(), vector<int>(1 << dirtyCount, -1)));
    depth[startX][startY][0] = 0;
    q.push({startX, startY, 0});
    while (!q.empty()) {
        int hereX = get<0>(q.front());
        int hereY = get<1>(q.front());
        int hereDirty = get<2>(q.front());
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nX = hereX + dx[i];
            int nY = hereY + dy[i];
            if (isInBoard(nX, nY, board[0].size(), board.size()) && depth[nX][nY][hereDirty] == -1 && board[nX][nY] != 'x') {
                if (board[nX][nY] == '.') {
                    depth[nX][nY][hereDirty] = depth[hereX][hereY][hereDirty] + 1;
                    q.push({nX, nY, hereDirty});
                } else {
                    int nextDirty = hereDirty | (1 << board[nX][nY]);
                    if (nextDirty == (1 << dirtyCount) - 1) {
                        return depth[hereX][hereY][hereDirty] + 1;
                    }
                    depth[nX][nY][nextDirty] = depth[hereX][hereY][hereDirty] + 1;
                    q.push({nX ,nY, nextDirty});
                }
            }
        }
    }
    return -1;
}

int main() {
    int w, h;
    scanf("%d %d", &w, &h);
    getchar();
    while (w != 0 || h != 0) {
        vector<vector<char>> board(h, vector<char>(w));
        int dirtyCount = 0;
        pair<int, int> robotPos;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                board[i][j] = getchar();
                if (board[i][j] == '*') {
                    board[i][j] = dirtyCount++;
                } else if (board[i][j] == 'o') {
                    robotPos = {i, j};
                    board[i][j] = '.';
                }
            }
            getchar();
        }
        printf("%d\n", bfs(board, robotPos.first, robotPos.second, dirtyCount));
        scanf("%d %d", &w, &h);
        getchar();
    }
    return 0;
}