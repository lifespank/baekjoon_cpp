#include <cstdio>
#include <tuple>
#include <queue>

using namespace std;

char board[8][8];
bool visited[8][8][50];
int dx[9] = {1, -1, 0, 0, -1, 1, -1, 1, 0};
int dy[9] = {0, 0, 1, -1, 1, 1, -1, -1, 0};

bool isInBoard(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

void fallDown() {
    for (int c = 0; c < 8; c++) {
        for (int r = 7; r >= 1; r--) {
            board[r][c] = board[r - 1][c];
        }
        board[0][c] = '.';
    }
}

bool bfs() {
    queue<tuple<int, int, int>> q;
    q.push({7, 0, 0});
    visited[7][0][0] = true;
    int currTime = 0;
    while (!q.empty()) {
        int hX = get<0>(q.front());
        int hY = get<1>(q.front());
        int hTime = get<2>(q.front());
        if (!hX && hY == 7) {
            return true;
        }
        q.pop();
        if (hTime > currTime) {
            currTime = hTime;
            fallDown();
        }
        if (board[hX][hY] == '#') {
            continue;
        }
        for (int i = 0; i < 9; i++) {
            int nX = hX + dx[i];
            int nY = hY + dy[i];
            int nTime = hTime + 1;
            if (isInBoard(nX, nY) && board[nX][nY] == '.' && !visited[nX][nY][nTime]) {
                q.push({nX, nY, nTime});
                visited[nX][nY][nTime] = true;
            }
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = getchar();
        }
        getchar();
    }
    printf("%d", bfs());
    return 0;
}