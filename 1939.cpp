#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

vector<pair<int, int>> graph[10001];
int N, M;
int dist[10001];

void dijkstra(int start) {
    priority_queue<pair<int, int>> q;
    q.push({INF, start});
    dist[start] = INF;
    while(!q.empty()) {
        int here = q.top().second;
        q.pop();
        for(auto adj : graph[here]) {
            int next = adj.first;
            int nextCost = adj.second;
            if(dist[next] < min(nextCost, dist[here])) {
                dist[next] = min(nextCost, dist[here]);
                q.push({dist[next], next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int start, dest;
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int from, to, val;
        cin >> from >> to >> val;
        bool plzAdd = true;
        for(int i = 0; i < graph[from].size(); i++) {
            if(graph[from][i].first == to) {
                plzAdd = false;
                if(graph[from][i].second < val) {
                    graph[from][i].second = val;
                }
                break;
            }
        }
        if(plzAdd) {
            graph[from].push_back({to, val});
        }
        plzAdd = true;
        for(int i = 0; i < graph[to].size(); i++) {
            if(graph[to][i].first == from) {
                plzAdd = false;
                if(graph[to][i].second < val) {
                    graph[to][i].second = val;
                }
                break;
            }
        }
        if(plzAdd) {
            graph[to].push_back({from, val});
        }
    }
    cin >> start >> dest;
    dijkstra(start);
    cout << dist[dest];

    return 0;
}