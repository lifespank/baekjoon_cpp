#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int N, M;
int dist[101][101];

void FloydWarshall() {
    for(int m = 1; m <= N; m++) {
        for(int s = 1; s <= N; s++) {
            for(int e = 1; e <= N; e++) {
                if(dist[s][e] > dist[s][m] + dist[m][e]) {
                    dist[s][e] = dist[s][m] + dist[m][e];
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
            }
            else {
                dist[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < M; i++) {
        int from, to, val;
        cin >> from >> to >> val;
        if(dist[from][to] > val) {
            dist[from][to] = val;
        }
    }
    FloydWarshall();
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(dist[i][j] != INF) {
                cout << dist[i][j] << ' ';
            }
            else {
                cout << "0 ";
            }
        }
        cout << '\n';
    }
    return 0;
}