#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int V, E, K;
vector<pair<int, int>> graph[20001];
int dist[20001];

void dijkstra(int start) {
    dist[start] = 0;
    priority_queue<pair<int, int>> q;
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
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill(dist, dist + 20001, INF);
    cin >> V >> E;
    cin >> K;
    for(int i = 0; i < E; i++) {
        int from, to, val;
        cin >> from >> to >> val;
        graph[from].push_back({to, val});
    }
    dijkstra(K);
    for(int i = 1; i <= V; i++) {
        if(dist[i] == INF) {
            cout << "INF";
        }
        else {
            cout << dist[i];
        }
        cout << '\n';
    }
    return 0;
}