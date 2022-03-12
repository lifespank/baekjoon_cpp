#include <iostream>
#include <cstring>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

int T, M, N, K;
int board[50][50];
bool visited[50][50];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int wormCount = 0;

void bfs(int startX, int startY) {
    if(visited[startX][startY]) {
        return;
    }
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    wormCount++;
    while(!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nX = tmp.first + dx[i];
            int nY = tmp.second + dy[i];
            if(nX >= 0 && nX < N && nY >= 0 && nY < M && !visited[nX][nY] && board[nX][nY] == 1) {
                q.push({nX, nY});
                visited[nX][nY] = true;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for(int i = 0; i < T; i++) {
        memset(visited, 0, sizeof(visited));
        memset(board, 0, sizeof(board));
        cin >> N >> M >> K;
        wormCount = 0;
        for(int j = 0; j < K; j++) {
            int x, y;
            cin >> x >> y;
            board[x][y] = 1;
        }
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                if(board[j][k] == 1) {
                    bfs(j, k);
                }
            }
        }
        cout << wormCount << '\n';
    }

    return 0;
}