#include <cstdio>
#include <queue>
#include <tuple>

using namespace std;

int N, M, K;
int depth[1000][1000][11][2];
int board[1000][1000];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isInBoard(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int bfs() {
    queue<tuple<int, int ,int ,bool>> q;
    q.push({0, 0, 0, true});
    depth[0][0][0][true] = 1;
    while (!q.empty()) {
        int hereX = get<0>(q.front());
        int hereY = get<1>(q.front());
        int hereBreak = get<2>(q.front());
        bool hereDay = get<3>(q.front());
        if (hereX == N - 1 && hereY == M - 1) {
            return depth[hereX][hereY][hereBreak][hereDay];
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nX = hereX + dx[i];
            int nY = hereY + dy[i];
            if (isInBoard(nX, nY) && (hereDay || !hereDay && !board[nX][nY])) {
                int nBreak = hereBreak + board[nX][nY];
                if (nBreak <= K && !depth[nX][nY][nBreak][!hereDay]) {
                    q.push({nX, nY, nBreak, !hereDay});
                    depth[nX][nY][nBreak][!hereDay] = depth[hereX][hereY][hereBreak][hereDay] + 1;
                }
            }
        }
        if (!depth[hereX][hereY][hereBreak][!hereDay]) {
            q.push({hereX, hereY, hereBreak, !hereDay});
            depth[hereX][hereY][hereBreak][!hereDay] = depth[hereX][hereY][hereBreak][hereDay] + 1;
        }
    }
    return -1;
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &board[i][j]);
        }
    }
    printf("%d", bfs());
    return 0;
}