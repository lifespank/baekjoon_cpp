#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
#include <bits/stdc++.h>

using namespace std;

int N, M, H;
int board[100][100][100];
int visited[100][100][100];
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
vector<tuple<int, int, int>> initialTomato;
int totalTomato = 0;
int ripeTomato = 0;

bool isInBoard(int x, int y, int z) {
    return x >= 0 && x < N && y >= 0 && y < M && z >= 0 && z < H;
}

int bfs() {
    queue<tuple<int, int, int>> q;
    for(int i = 0; i < initialTomato.size(); i++) {
        q.push(initialTomato[i]);
        visited[get<0>(initialTomato[i])][get<1>(initialTomato[i])][get<2>(initialTomato[i])] = 0;
        ripeTomato++;
    }
    if(ripeTomato == totalTomato) {
        return 0;
    }
    while(!q.empty()) {
        tuple<int, int, int> here = q.front();
        q.pop();
        int depth = visited[get<0>(here)][get<1>(here)][get<2>(here)];
        
        for(int i = 0; i < 6; i++) {
            int nX = get<0>(here) + dx[i];
            int nY = get<1>(here) + dy[i];
            int nZ = get<2>(here) + dz[i];
            if(isInBoard(nX, nY, nZ) && visited[nX][nY][nZ] == -1 && board[nX][nY][nZ] == 0) {
                q.push({nX, nY, nZ});
                board[nX][nY][nZ] = 1;
                visited[nX][nY][nZ] = depth + 1;
                ripeTomato++;
                if(ripeTomato == totalTomato) {
                    return depth + 1;
                }
            }
        }
    }
    return -1;
}

int main() {
    memset(visited, -1, sizeof(visited));
    cin >> M >> N >> H;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                cin >> board[j][k][i];
                if(board[j][k][i] == 1) {
                    initialTomato.push_back({j, k, i});
                }
                if(board[j][k][i] != -1) {
                    totalTomato++;
                }
            }
        }
    }
    cout << bfs();
    return 0;
}