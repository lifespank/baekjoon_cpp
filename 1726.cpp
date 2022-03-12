#include <iostream>
#include <queue>
#include <bits/stdc++.h>
#include <memory.h>

using namespace std;

int M, N;
int board[100][100];
int depth[100][100][4];
int dDir[2] = {1, 3};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

class robotState {
    public:
    robotState(int x, int y, int dir): x(x), y(y), dir(dir) {}
    int x;
    int y;
    int dir;
};

bool isInBoard(int x, int y) {
    return x >= 0 && x < M && y >= 0 && y < N;
}

int changeDir(int dir) {
    switch(dir) {
        case 1:
        dir = 0;
        break;
        case 2:
        dir = 2;
        break;
        case 3:
        dir = 1;
        break;
        case 4:
        dir = 3;
        break;
        default:
        break;
    }
    return dir;
}

int bfs(robotState startState, robotState destState) {
    depth[startState.x][startState.y][startState.dir] = 0;
    queue<robotState> q;
    q.push(startState);
    while(!q.empty()) {
        int hereX = q.front().x;
        int hereY = q.front().y;
        int hereDir = q.front().dir;
        int dth = depth[hereX][hereY][hereDir];
        q.pop();
        if(hereX == destState.x && hereY == destState.y && hereDir == destState.dir) {
            return dth;
        }
        for(int i = 0; i < 2; i++) {
            int nDir = (hereDir + dDir[i]) % 4;
            if(depth[hereX][hereY][nDir] == -1) {
                robotState newState(hereX, hereY, nDir);
                q.push(newState);
                depth[hereX][hereY][nDir] = dth + 1;
            }
        }
        for(int i = 1; i <= 3; i++) {
            int nX = hereX + i * dx[hereDir];
            int nY = hereY + i * dy[hereDir];
            if(isInBoard(nX, nY) && !board[nX][nY] && (depth[nX][nY][hereDir] == -1 || depth[nX][nY][hereDir] > dth + 1)) {
                robotState newState(nX, nY, hereDir);
                q.push(newState);
                depth[nX][nY][hereDir] = dth + 1;
            }
            if(!isInBoard(nX, nY) || board[nX][nY]) {
                break;
            }
        }   
    }
    return -1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;
    memset(depth, -1, sizeof(depth));
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    int x, y, dir;
    cin >> x >> y >> dir;
    robotState startState(x - 1, y - 1, changeDir(dir));
    cin >> x >> y >> dir;
    robotState destState(x - 1, y - 1, changeDir(dir));
    cout << bfs(startState, destState);
    return 0;
}