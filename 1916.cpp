#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#define INF 1e8

using namespace std;

int n, m, start, dest;
vector<pair<int, int>> graph[1001];
int dist[1001];

void dijkstra() {
    fill(dist, dist + 1001, INF);
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
    
    cin >> n;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int from, to, val;
        cin >> from >> to >> val;
        bool plzAdd = true;
        for(int i = 0; i < graph[from].size(); i++) {
            if(graph[from][i].first == to) {
                plzAdd = false;
                if(graph[from][i].second > val) {
                    graph[from][i].second = val;
                }
                break;
            }
        }
        if(plzAdd) {
            graph[from].push_back({to, val});
        }
    }
    cin >> start >> dest;
    dijkstra();
    cout << dist[dest];
    return 0;
}