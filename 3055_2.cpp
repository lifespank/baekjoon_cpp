#include <cstdio>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int R, C, startX, startY;
char board[50][50];
int depth[50][50];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isInBoard(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

void waterSpread(queue<pair<int, int>>& waterQ, queue<pair<int, int>> tempWaterQ) {
    while (!tempWaterQ.empty()) {
        int hX = tempWaterQ.front().first;
        int hY = tempWaterQ.front().second;
        tempWaterQ.pop();
        for (int i = 0; i < 4; i++) {
            int nX = hX + dx[i];
            int nY = hY + dy[i];
            if (isInBoard(nX, nY) && board[nX][nY] == '.') {
                board[nX][nY] = '*';
                waterQ.push({nX, nY});
            }
        }
    }
}

int bfs(queue<pair<int, int>>& waterQ) {
    int currTime = 0;
    queue<tuple<int, int, int>> q;
    q.push({startX, startY, currTime});
    depth[startX][startY] = 0;
    while (!q.empty()) {
        int hX = get<0>(q.front());
        int hY = get<1>(q.front());
        int hTime = get<2>(q.front());
        if (board[hX][hY] == 'D') {
            return depth[hX][hY];
        }
        if (hTime == currTime) {
            currTime = hTime + 1;
            waterSpread(waterQ, waterQ);
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nX = hX + dx[i];
            int nY = hY + dy[i];
            int nTime = hTime + 1;
            if (isInBoard(nX, nY) && (board[nX][nY] == '.' || board[nX][nY] == 'D') && depth[nX][nY] < 0) {
                q.push({nX, nY, nTime});
                depth[nX][nY] = depth[hX][hY] + 1;
            }
        }
    }
    return -1;
}

int main() {
    memset(depth, -1, sizeof(depth));
    scanf("%d %d", &R, &C);
    getchar();
    queue<pair<int, int>> waterQ;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            board[i][j] = getchar();
            if (board[i][j] == 'S') {
                startX = i;
                startY = j;
                board[i][j] = '.';
            } else if (board[i][j] == '*') {
                waterQ.push({i, j});
            }
        }
        getchar();
    }
    int ans = bfs(waterQ);
    if (ans < 0) {
        printf("KAKTUS");
    } else {
        printf("%d", ans);
    }
    return 0;
}