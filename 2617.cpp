#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <vector>
#define INF 1e9

using namespace std;

int N, M;
int dist[101][101];
int dist2[101][101];


void FloydWarshall() {
    for(int m = 1; m <= N; m++) {
        for(int s = 1; s <= N; s++) {
            for(int e = 1; e <= N; e++) {
                if(dist[s][e] > dist[s][m] + dist[m][e]) {
                    dist[s][e] = dist[s][m] + dist[m][e];
                }
                if(dist2[s][e] > dist2[s][m] + dist2[m][e]) {
                    dist2[s][e] = dist2[s][m] + dist2[m][e];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i < N + 1; i++) {
        for(int j = 1; j <= N; j++) {
            if(i != j) {
                dist[i][j] = INF;
                dist2[i][j] = INF;
            }
            else {
                dist[i][j] = 0;
                dist2[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        if(dist[from][to] > 1) {
            dist[from][to] = 1;
        }
        if(dist2[to][from] > 1) {
            dist2[to][from] = 1;
        }
    }
    FloydWarshall();
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        int inCount = 0;
        int outCount = 0;
        for(int j = 1; j <= N; j++) {
            if(dist[i][j] != INF && dist[i][j] != 0) {
                inCount++;
            }
            if(dist2[i][j] != INF && dist2[i][j] != 0) {
                outCount++;
            }
        }
        if(inCount >= (N + 1) / 2 || outCount >= (N + 1) / 2) {
            ans++;
        }
    }
    cout << ans;

    return 0;
}