#include <iostream>
#include <bits/stdc++.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int N, M;
int board[300][300];
bool visited[300][300];
int yearsSpent = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int totalChunk = 0;

bool isInBoard(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int countBlank(int x, int y) {
    int counts = 0;
    for(int i = 0; i < 4; i++) {
        int nX = x + dx[i];
        int nY = y + dy[i];
        if(isInBoard(nX, nY) && board[nX][nY] == 0) {
            counts++;
        }
    }
    return counts;
}

void spendYear() {
    vector<tuple<int, int, int>> m;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] > 0) {
                m.push_back({i, j, countBlank(i, j)});
            }
        }
    }
    for(auto it = m.begin(); it != m.end(); it++) {
        board[get<0>(*it)][get<1>(*it)] -= get<2>(*it);
        if(board[get<0>(*it)][get<1>(*it)] < 0) {
            board[get<0>(*it)][get<1>(*it)] = 0;
        }
    }
    yearsSpent++;
}

void bfs(int x, int y) {
    if(visited[x][y]) {
        return;
    }
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while(!q.empty()) {
        pair<int, int> here = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nX = here.first + dx[i];
            int nY = here.second + dy[i];
            if(isInBoard(nX, nY) && board[nX][nY] > 0 && !visited[nX][nY]) {
                q.push({nX, nY});
                visited[nX][nY] = true;
            }
        }
    }
}

bool isSeparated() {
    memset(visited, 0, sizeof(visited));
    totalChunk = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] > 0 && !visited[i][j]) {
                if(totalChunk > 0) {
                    return true;
                }
                bfs(i, j);
                totalChunk++;
            }
        }
    }
    return false;
}

bool allMelt() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] > 0) {
                return false;
            }
        }
    }
    return true;
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
    while(!isSeparated()) {
        if(allMelt()) {
            yearsSpent = 0;
            break;
        }
        spendYear();
    }
    cout << yearsSpent;
    return 0;
}
