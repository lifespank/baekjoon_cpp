#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <memory.h>

using namespace std;

int N;
int board[20][20];
int visited[20][20];
pair<int, int> sharkPos;
int sharkSize;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int totalTime = 0;
int eatenFish = 0;

bool isInBoard(int x, int y) {  //좌표 유효성 확인
    return x >= 0 && x < N && y >= 0 && y < N;
}

int fishDistance(pair<int, int> dest) {   //물고기와의 거리 반환
    memset(visited, -1, sizeof(visited));
    queue<pair<int, int>> q;
    q.push(sharkPos);
    visited[sharkPos.first][sharkPos.second] = 0;
    while(!q.empty()) {
        pair<int, int> here = q.front();
        int depth = visited[here.first][here.second];
        if(here == dest) {
            return depth;
        }
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nX = here.first + dx[i];
            int nY = here.second + dy[i];
            if(isInBoard(nX, nY) && visited[nX][nY] == -1 && board[nX][nY] <= sharkSize) {
                q.push({nX, nY});
                visited[nX][nY] = depth + 1;
            }
        }

    }
    return 1e9;   //도달할 수 없을 시 1e9 반환
}

void findFish() {
    pair<int ,int> fishPos;
    int minDis = 1e9;
    do {      //먹을 물고기가 없을 시 minDis == 1e9, 이 때 루프 탈출
        minDis = 1e9;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(board[i][j] != 0 && board[i][j] < sharkSize) {  //루프를 돌며 fishDistance를 호출해 minDis를 최신화
                    int distance = fishDistance({i, j});
                    if(distance < minDis) {
                        minDis = distance;
                        fishPos = {i, j};
                    }   
                }
            }
        }
        if(minDis < 1e9) {    //먹을 물고기를 찾았을 시 물고기를 먹는 과정을 구현하고 totalTime에 더해줌
            eatenFish++;
            if(eatenFish == sharkSize) {
                eatenFish = 0;
                sharkSize++;
            }
            board[fishPos.first][fishPos.second] = 0;
            sharkPos = fishPos;
            totalTime += minDis;
        }
    }while(minDis != 1e9);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sharkSize = 2;
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
            if(board[i][j] == 9) {
                sharkPos = {i, j};
                board[i][j] = 0;
            }
        }
    }
    findFish();
    cout << totalTime;
    return 0;
}