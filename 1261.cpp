#include <iostream>
#include <memory.h>
#include <queue>
#include <tuple>
#include <vector>
#define INF 1e9

using namespace std;

int N, M;
vector<tuple<int, int, int>> graph[100][100];
int board[100][100];
int dist[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0,};


bool isInBoard(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

void dijkstra() {
    for(int i = 0; i < 100; i++) {
        fill(dist[i], dist[i] + 100, INF);
    }
    dist[0][0] = 0;
    priority_queue<tuple<int, int ,int>> q;
    q.push({-dist[0][0], 0, 0});
    while(!q.empty()) {
        int hereX = get<1>(q.top());
        int hereY = get<2>(q.top());
        q.pop();
        for(int i = 0; i < graph[hereX][hereY].size(); i++) {
            int nextX = get<0>(graph[hereX][hereY][i]);
            int nextY = get<1>(graph[hereX][hereY][i]);
            int nextCost = get<2>(graph[hereX][hereY][i]);
            if(dist[nextX][nextY] > dist[hereX][hereY] + nextCost) {
                dist[nextX][nextY] = dist[hereX][hereY] + nextCost;
                q.push({-dist[nextX][nextY], nextX, nextY});
            }
        }
    }
}

int main() {
    cin >> M >> N;
    getchar();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            board[i][j] = getchar() - '0';
        }
        getchar();
    }


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            for(int k = 0; k < 4; k++) {
                int nX = i + dx[k];
                int nY = j + dy[k];
                if(isInBoard(nX, nY)) {
                    graph[i][j].push_back({nX, nY, board[nX][nY]});
                }
            }
        }
    }

    dijkstra();
    cout << dist[N - 1][M - 1];
    return 0;
}