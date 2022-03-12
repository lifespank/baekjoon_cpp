#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int N, M;
vector<vector<int>> board(8, vector<int>(8, 0));
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<vector<int>> dirs[6];
vector<tuple<int, int, int>> cameras;
int minNum = 1e9;

int blindSpot(vector<vector<int>> board) {
    int total = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(!board[i][j]) {
                total++;
            }
        }
    }
    return total;
}

bool isInBoard(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

void watch(vector<vector<int>>& board, int dir, int startX, int startY) {
    int nX = startX + dx[dir];
    int nY = startY + dy[dir];
    while(isInBoard(nX, nY) && board[nX][nY] != 6) {
        if(board[nX][nY] == 0) {
            board[nX][nY] = '#';
        }
        nX += dx[dir];
        nY += dy[dir];
    }
}

void calc(int camIdx, vector<vector<int>> board) {
    if(camIdx == cameras.size()) {
        minNum = min(minNum, blindSpot(board));
        return;
    }
    int camNum = get<0>(cameras[camIdx]);
    int x = get<1>(cameras[camIdx]);
    int y = get<2>(cameras[camIdx]);
    for(int i = 0; i < dirs[camNum].size(); i++) {
        vector<vector<int>> newBoard = board;
        for(int j = 0; j < dirs[camNum][i].size(); j++) {
            watch(newBoard, dirs[camNum][i][j], x, y);
        }
        calc(camIdx + 1, newBoard);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dirs[1] = {{0}, {1}, {2}, {3}};
    dirs[2] = {{0, 2}, {1, 3}};
    dirs[3] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
    dirs[4] = {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}};
    dirs[5] = {{0, 1, 2, 3}};
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if(1 <= board[i][j] && board[i][j] <= 5) {
                cameras.push_back({board[i][j], i, j});
            }
        }
    }
    calc(0, board);
    cout << minNum;
    return 0;
}