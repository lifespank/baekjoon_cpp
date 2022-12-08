#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int W, H, startX, startY, targetX, targetY;
char board[100][100];
int depth[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool isInBoard(int x, int y) {
    return x >= 0 && x < H && y >= 0 && y < W;
}

int bfs() {
    queue<pair<int, int>> q;
    depth[startX][startY] = 0;
    q.push({startX, startY});
    while (!q.empty()) {
        int hX = q.front().first;
        int hY = q.front().second;
        if (hX == targetX && hY == targetY) {
            return depth[hX][hY];
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nX = hX + dx[i];
            int nY = hY + dy[i];
            while (isInBoard(nX, nY) && board[nX][nY] != '*') {
                if (depth[nX][nY] < 0) {
                    q.push({nX, nY});
                    depth[nX][nY] = depth[hX][hY] + 1;
                }
                nX += dx[i];
                nY += dy[i];
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &W, &H);
    getchar();
    startX = -1;
    memset(depth, -1, sizeof(depth));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            board[i][j] = getchar();
            if (board[i][j] == 'C') {
                if (startX < 0) {
                    startX = i;
                    startY = j;
                } else {
                    targetX = i;
                    targetY = j;
                }
            }
        }
        getchar();
    }
    printf("%d", bfs() - 1);
    return 0;
}