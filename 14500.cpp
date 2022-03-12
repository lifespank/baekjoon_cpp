#include <iostream>
#include <bits/stdc++.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int N, M;
int board[500][500];
bool visited[500][500];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
//ㅗ모양 테트로미노의 좌표를 미리 저장
int fuqShapeX[4][4] = {{0, 0, 0, 1}, {0, 1, 2, 1}, {0, 0, 0, -1}, {0, -1, 0, 1}};
int fuqShapeY[4][4] = {{0, 1, 2, 1}, {0, 0, 0, 1}, {0, 1, 2, 1}, {0, 1, 1, 1}};
int maxVal;

//x, y가 범위 내에 있는가
bool isInBoard(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

//dfs 탐색을 하여 깊이가 4일 때 maxVal 최신화
void dfs(int startX, int startY, int depth, int val) {
    if(depth == 4) {
        maxVal = max(maxVal, val);
    }
    else {
        for(int i = 0; i < 4; i++) {
            int nX = startX + dx[i];
            int nY = startY + dy[i];
            if(isInBoard(nX, nY) && !visited[nX][nY] && depth < 4) {
                visited[nX][nY] = true;
                dfs(nX, nY, depth + 1, val + board[nX][nY]);
                visited[nX][nY] = false;   //탐색을 한 후 다시 visited를 false로 두어 모든 경우의 수를 탐색할 수 있도록 한다.
            }
        }
    }
}


//ㅗ 모양 테트로미노에 해당하는 값을 구하는 함수
void fuq(int x, int y) {
    for(int i = 0; i < 4; i++) {
        bool isBroken = false;
        int val = 0;
        for(int j = 0; j < 4; j++) {
            int nX = x + fuqShapeX[i][j];
            int nY = y + fuqShapeY[i][j];
            if(!isInBoard(nX, nY)) {
                isBroken = true; //nX, nY가 범위 내에 없을 시(테트로미노를 완성할 수 없을 시) 플래그를 set 후 break
                break;
            }
            else {
                val += board[nX][nY];
            }
        }
        if(!isBroken) {         //테트로미노를 만들 수 있는 경우 maxVal 최신화
            maxVal = max(maxVal, val);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            visited[i][j] = true;        
            dfs(i, j, 1, board[i][j]);  //해당 좌표의 ㅗ 모양을 제외한 테트로미노
            visited[i][j] = false;
            fuq(i, j);  //해당 좌표의 ㅗ 모양 테트로미노
        }
    }
    cout << maxVal;
    return 0;
}