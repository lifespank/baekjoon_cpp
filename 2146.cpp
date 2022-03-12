#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

int N, board[100][100];
int visited[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<pair<int, int>> initCont[10000];

bool isInBoard(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

void dfs(int x, int y, int contNum) {
    visited[x][y] = true;
    board[x][y] = contNum;
    initCont[contNum].push_back({x, y});
    for(int i = 0; i < 4; i++) {
        int nX = x + dx[i];
        int nY = y + dy[i];
        if(isInBoard(nX, nY) && board[nX][nY] == 1 && !visited[nX][nY]) {
            dfs(nX, nY, contNum);
        }
    }
}

int bfs(int contNum) {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    for(int i = 0; i < initCont[contNum].size(); i++) {
        q.push(initCont[contNum][i]);
    }
    while(!q.empty()) {
        int hereX = q.front().first;
        int hereY = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nX = hereX + dx[i];
            int nY = hereY + dy[i];
            if(isInBoard(nX, nY) && !board[nX][nY] && !visited[nX][nY]) {
                q.push({nX, nY});
                visited[nX][nY] = visited[hereX][hereY] + 1;
            }
            else if(isInBoard(nX, nY) && board[nX][nY] && board[nX][nY] != contNum) {
                return visited[hereX][hereY];
            }
        }
    }
    return 1e9;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    int contNum = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visited[i][j] && board[i][j] == 1) {
                dfs(i, j, contNum);
                contNum++;
            }
        }
    }
    int minLen = 1e9;
    for(int i = 1; i < contNum; i++) {
        minLen = min(minLen, bfs(i));
    }
    cout << minLen;



    return 0;
}