#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <tuple>
#define INF 1e9

int N;
int board[125][125];
int dist[125][125];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

using namespace std;

bool isInBoard(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

void dijkstra() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            dist[i][j] = INF;
        }
    }
    dist[0][0] = board[0][0];
    priority_queue<tuple<int, int, int>> q;
    q.push({-dist[0][0], 0, 0});
    while(!q.empty()) {
        int hereX = get<1>(q.top());
        int hereY = get<2>(q.top());
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nX = hereX + dx[i];
            int nY = hereY + dy[i];
            if(isInBoard(nX, nY) && dist[hereX][hereY] + board[nX][nY] < dist[nX][nY]) {
                dist[nX][nY] = dist[hereX][hereY] + board[nX][nY];
                q.push({-dist[nX][nY], nX, nY});
            }
        } 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int pnum = 1;
    while(N != 0) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> board[i][j];
            }
        }
        dijkstra();
        cout << "Problem " << pnum << ": " << dist[N - 1][N - 1] << "\n";
        cin >> N;
        pnum++;
    }
    return 0;
}