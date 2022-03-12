#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int N, M, H;
bool board[11][31];
int minNum = 1e9;

pair<int, int> incIdx(int x, int y) {
    y++;
    if(y > H) {
        y = 1;
        x++;
    }
    return {x, y};
}

bool isGoodToPlace(int x, int y, bool board[][31]) {
    if(board[x][y]) {
        return false;
    }
    if(x > 1 && board[x - 1][y]) {
        return false;
    } else if(x < N && board[x + 1][y]) {
        return false;
    }
    return true;
}

bool isValid(bool board[][31]) {
    for(int i = 1; i <= N; i++) {
        int num = i;
        for(int j = 1; j <= H; j++) {
            if(board[num][j]) {
                num++;
            } else if(num > 1 && board[num - 1][j]) {
                num--;
            }
        }
        if(num != i) {
            return false;
        }
    }
    return true;
}

void dfs(int x, int y, bool board[][31], int howMany) {
    if(isValid(board)) {
        minNum = min(minNum, howMany);
        return;
    }
    if(x == N || howMany == 3) {
        return;
    }
    bool newBoard[11][31] = {0};
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= H; j++) {
            newBoard[i][j] = board[i][j];
        }
    }
    pair<int, int> newIdx = incIdx(x, y);
    if(isGoodToPlace(x, y, newBoard)) {
        newBoard[x][y] = true;
        dfs(newIdx.first, newIdx.second, newBoard, howMany + 1);
        newBoard[x][y] = false;
    }
    dfs(newIdx.first, newIdx.second, newBoard, howMany);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> H;
    for(int i = 0; i < M; i++) {
        int h, v;
        cin >> h >> v;
        board[v][h] = true;
    }
    dfs(1, 1, board, 0);
    if(minNum == 1e9) {
        minNum = -1;
    }
    cout << minNum;
    return 0;
}