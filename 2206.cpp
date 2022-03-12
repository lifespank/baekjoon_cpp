#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#include <tuple>

using namespace std;

int N, M;
int board[1000][1000];
int visit[1000][1000][2];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void consumeBuffer() {
    while(getchar() != '\n') {}
}

bool isInBoard(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int bfs(pair<int, int> start, pair<int, int> dest) {
    visit[start.first][start.second][0] = 1;
    queue<tuple<int, int, bool>> q;
    q.push({start.first, start.second, false});
    while(!q.empty()) {
        int hereX = get<0>(q.front());
        int hereY = get<1>(q.front());
        bool broken = get<2>(q.front());
        int depth = visit[hereX][hereY][broken];
        if(hereX == dest.first && hereY == dest.second) {
            return depth;
        }
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nX = hereX + dx[i];
            int nY = hereY + dy[i];
            if(isInBoard(nX, nY) && visit[nX][nY][broken] == -1) {
                if(board[nX][nY] == 0) {
                    q.push({nX, nY, broken});
                    visit[nX][nY][broken] = depth + 1;
                }
                else if(!broken) {
                    q.push({nX, nY, !broken});
                    visit[nX][nY][!broken] = depth + 1;
                }
            }
        }
    }
    return -1;
}


int main() {
    cin >> N >> M;
    consumeBuffer();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            board[i][j] = (int)(getchar() - '0');
        }
        consumeBuffer();
    }
    memset(visit, -1, sizeof(visit));
    cout << bfs({0, 0}, {N - 1, M - 1});
    return 0;
}