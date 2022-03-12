#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#include <cstdio>

using namespace std;

int R, C;
char board[1000][1000];
int depth[1000][1000];
int fireMap[1000][1000];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
pair<int, int> jihunPos;
bool isInBoard(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

void fireMove(vector<pair<int, int>> firePos) {
    queue<pair<int, int>> q;
    for(auto p : firePos) {
        q.push(p);
        fireMap[p.first][p.second] = 0;
    }
    while(!q.empty()) {
        int hereX = q.front().first;
        int hereY = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nX = hereX + dx[i];
            int nY = hereY + dy[i];
            if(isInBoard(nX, nY) && board[nX][nY] == '.' && fireMap[nX][nY] == -1) {
                fireMap[nX][nY] = fireMap[hereX][hereY] + 1;
                q.push({nX, nY});
            }
        }
    }
}

int jihunMove(int startX, int startY) {
    depth[startX][startY] = 0;
    if(startX == 0 || startX == R - 1 || startY == 0 || startY == C - 1) {
        return 0;
    }
    queue<pair<int, int>> q;
    q.push({startX, startY});
    while(!q.empty()) {
        int hereX = q.front().first;
        int hereY = q.front().second;
        int dth = depth[hereX][hereY];
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nX = hereX + dx[i];
            int nY = hereY + dy[i];
            if(isInBoard(nX, nY) && depth[nX][nY] == -1 && board[nX][nY] == '.' && (fireMap[nX][nY] > dth + 1 || fireMap[nX][nY] == -1)) {
                depth[nX][nY] = dth + 1;
                if(nX == 0 || nX == R - 1 || nY == 0 || nY == C - 1) {
                    return depth[nX][nY];
                }
                q.push({nX, nY});
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &R, &C);
    getchar();
    vector<pair<int, int>> firePos;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            board[i][j] = getchar();
            if(board[i][j] == 'J') {
                jihunPos = {i, j};
                board[i][j] = '.';
            }
            else if(board[i][j] == 'F') {
                firePos.push_back({i, j});
            }
        }
        getchar();
    }
    memset(depth, -1, sizeof(depth));
    memset(fireMap, -1, sizeof(fireMap));
    fireMove(firePos);
    int ans = jihunMove(jihunPos.first, jihunPos.second);
    if(ans == -1) {
        printf("IMPOSSIBLE");
    }
    else {
        printf("%d", ans + 1);
    }
    
    return 0;
}