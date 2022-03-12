#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N;
char board[100][100];
bool visit[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void consumeBuffer() {
    while(getchar() != '\n') {}
}

bool isInBoard(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

void dfs(char c, pair<int, int> start, bool blind) {
    visit[start.first][start.second] = true;
    for(int i = 0; i < 4; i++) {
        int nX = start.first + dx[i];
        int nY = start.second + dy[i];
        if(!blind) {
            if(isInBoard(nX, nY) && !visit[nX][nY] && board[nX][nY] == c) {
                dfs(c, {nX, nY}, blind);
            }
        }
        else {
            if(isInBoard(nX, nY) && !visit[nX][nY] && (board[nX][nY] == 'R' || board[nX][nY] == 'G')) {
                dfs(c, {nX, nY}, blind);
            }
        }
    }
}

int countArea(char c, bool blind) {
    memset(visit, 0, sizeof(visit));
    int count = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!blind) {
                if(board[i][j] == c && !visit[i][j]) {
                    count++;
                    dfs(c, {i, j}, blind);
                }
            }
            else {
                if((board[i][j] == 'R' || board[i][j] == 'G') && !visit[i][j]) {
                    count++;
                    dfs(c, {i, j}, blind);
                }
            }
        }
    }
    return count;
}

int main() {
    cin >> N;
    int rCount = 0;
    int gCount = 0;
    int bCount = 0;
    int rgCount = 0;
    consumeBuffer();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            board[i][j] = getchar();
        }
        consumeBuffer();
    }
    rCount = countArea('R', false);
    gCount = countArea('G', false);
    bCount = countArea('B', false);
    rgCount = countArea('X', true);
    cout << rCount + gCount + bCount << ' ' << rgCount + bCount;
    return 0;
    
}