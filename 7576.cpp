#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[1000][1000];
int visited[1000][1000];
vector<pair<int, int>> initialRipe;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int totalTomato = 0;
int ripeTomato = 0;

int bfs() {
    queue<pair<int, int>> q;
    for(int i = 0; i < initialRipe.size(); i++) {
        visited[initialRipe[i].first][initialRipe[i].second] = 0;
        q.push(initialRipe[i]);
    }
    while(!q.empty()) {
        pair<int, int> tmp = q.front();
        int depth = visited[tmp.first][tmp.second];
        ripeTomato++;
        if(totalTomato == ripeTomato) {
            return depth;
        }
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nX = tmp.first + dx[i];
            int nY = tmp.second + dy[i];
            if(nX >= 0 && nX < N && nY >= 0 && nY < M && visited[nX][nY] == -1 && board[nX][nY] == 0) {
                q.push({nX, nY});
                visited[nX][nY] = depth + 1;
            }
        }
    }
    return -1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;
    memset(visited, -1, sizeof(visited));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            if(board[i][j] != -1) {
                totalTomato++;
            }
            if(board[i][j] == 1) {
                initialRipe.push_back({i, j});
            }
        }
    }
    cout << bfs();
    return 0;
}