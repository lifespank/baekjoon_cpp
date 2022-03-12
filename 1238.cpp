#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
#define MAX 1001
#define INF 1e9

using namespace std;

int N, M, X, dist[MAX];
vector<pair<int, int>> graph[MAX];

int dijkstra(int start, int dest) {
    fill(dist, dist + MAX, INF);
    priority_queue<pair<int, int>> q;
    dist[start] = 0;
    q.push({-dist[start], start});
    while(!q.empty()) {
        int here = q.top().second;
        q.pop();
        for(int i = 0; i < graph[here].size(); i++) {
            int next = graph[here][i].first;
            int nextCost = graph[here][i].second;
            if(dist[next] > dist[here] + nextCost) {
                dist[next] = dist[here] + nextCost;
                q.push({-dist[next], next});
            }
        }
    }
    return dist[dest];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> X;
    for(int i = 0; i < M; i++) {
        int from, to, val;
        cin >> from >> to >> val;
        graph[from].push_back({to, val});
    }
    int maxTime = 0;
    for(int i = 1; i <= N; i++) {
        maxTime = max(maxTime, dijkstra(i, X) + dijkstra(X, i));
    }
    cout << maxTime;
    return 0;
}