#include <cstdio>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

char board[20][20];
int depth[20][20][20][20];
int N, M;
pair<int, int> coin[2];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isInBoard(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int bfs() {
    depth[coin[0].first][coin[0].second][coin[1].first][coin[1].second] = 0;
    queue<tuple<int, int, int, int>> q;
    q.push({coin[0].first, coin[0].second, coin[1].first, coin[1].second});
    while (!q.empty()) {
        int coin0x = get<0>(q.front());
        int coin0y = get<1>(q.front());
        int coin1x = get<2>(q.front());
        int coin1y = get<3>(q.front());
        q.pop();
        if (depth[coin0x][coin0y][coin1x][coin1y] >= 10) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nCoin0x = coin0x + dx[i];
            int nCoin0y = coin0y + dy[i];
            int nCoin1x = coin1x + dx[i];
            int nCoin1y = coin1y + dy[i];
            if (isInBoard(nCoin0x, nCoin0y) && !isInBoard(nCoin1x, nCoin1y) || !isInBoard(nCoin0x, nCoin0y) && isInBoard(nCoin1x, nCoin1y)) {
                return depth[coin0x][coin0y][coin1x][coin1y] + 1;
            }
            if (isInBoard(nCoin0x, nCoin0y) && isInBoard(nCoin1x, nCoin1y)) {
                if (board[nCoin0x][nCoin0y] == '#') {
                    nCoin0x = coin0x;
                    nCoin0y = coin0y;
                }
                if (board[nCoin1x][nCoin1y] == '#') {
                    nCoin1x = coin1x;
                    nCoin1y = coin1y;
                }
                if (depth[nCoin0x][nCoin0y][nCoin1x][nCoin1y] == -1 || depth[coin0x][coin0y][coin1x][coin1y] + 1 < depth[nCoin0x][nCoin0y][nCoin1x][nCoin1y]) {
                    depth[nCoin0x][nCoin0y][nCoin1x][nCoin1y] = depth[coin0x][coin0y][coin1x][coin1y] + 1;
                    q.push({nCoin0x, nCoin0y, nCoin1x, nCoin1y});
                }
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &N, &M);
    getchar();
    int coinIdx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            board[i][j] = getchar();
            if (board[i][j] == 'o') {
                coin[coinIdx].first = i;
                coin[coinIdx].second = j;
                coinIdx++;
                board[i][j] = '.';
            }
        }
        getchar();
    }
    memset(depth, -1, sizeof(depth));
    printf("%d", bfs());
    return 0;
}