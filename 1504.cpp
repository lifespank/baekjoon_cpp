#include <iostream>
#include <memory.h>
#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 1e8

using namespace std;

int N, E;
vector<pair<int, int>> graph[801];
int dist[801];


int dijkstra(int start, int dest) {
    fill(dist, dist + N + 1, INF);
    priority_queue<pair<int, int>> q;
    dist[start] = 0;
    q.push({-dist[start], start});
    while(!q.empty()) {
        int here = q.top().second;
        q.pop();
        for(auto it = graph[here].begin(); it != graph[here].end(); it++) {
            int next = it->first;
            int nextCost = it->second;
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
    cin >> N >> E;
    int v1, v2;
    for(int i = 0; i < E; i++) {
        int from, to, val;
        cin >> from >> to >> val;
        graph[from].push_back({to, val});
        graph[to].push_back({from, val});
    }
    cin >> v1 >> v2;
    int first_1, first_2, second_1, second_2, middle, firstTotal, secondTotal, realTotal;
    first_1 = dijkstra(1, v1);
    middle = dijkstra(v1, v2);
    first_2 = dijkstra(v2, N);
    second_1 = dijkstra(1, v2);
    second_2 = dijkstra(v1, N);
    firstTotal = first_1 + middle + first_2;
    secondTotal = second_1 + middle + second_2;
    realTotal = min(firstTotal, secondTotal);
    if(realTotal >= INF) {
        realTotal = -1;
    }
    cout << realTotal;

    return 0;
}