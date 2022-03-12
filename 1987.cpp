#include <iostream>
#include <algorithm>

using namespace std;

int R, C;
char board[20][20];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int visit = 0;
int maxVisit = 0;
void consumeLine() {
    while(getchar() != '\n') {}
}

void dfs(int startX, int startY, int depth) {
    maxVisit = max(maxVisit, depth);
    for(int i = 0; i < 4; i++) {
        int nX = startX + dx[i];
        int nY = startY + dy[i];
        if(nX >= 0 && nX < R && nY >= 0 && nY < C && (visit & (1 << (int)(board[nX][nY] - 'A'))) == 0) {
            visit = visit | 1 << (int)(board[nX][nY] - 'A');
            dfs(nX, nY, depth + 1);
            visit = visit & ~(1 << (int)(board[nX][nY] - 'A'));
        }
    }
    
}

int main() {
    cin >> R >> C;
    consumeLine();
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            board[i][j] = getchar();
        }
        consumeLine();
    }
    visit = visit | 1 << (int)(board[0][0] - 'A');
    dfs(0, 0, 1);
    cout << maxVisit;
    return 0;
}