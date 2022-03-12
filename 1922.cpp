#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;

vector<pair<int, int>> graph[1001];
int N, M;
bool visited[1001];
int totalDist = 0;

void prim() {
    priority_queue<pair<int, int>> q;
    for(int i = 0; i < graph[1].size(); i++) {
        q.push({-graph[1][i].second, graph[1][i].first});
    }
    visited[1] = true;
    while(!q.empty()) {
        int here = q.top().second;
        int hereDist = -q.top().first;
        q.pop();
        if(!visited[here]) {
            visited[here] = true;
            totalDist += hereDist;
            for(int i = 0; i < graph[here].size(); i++) {
                int nextDist = graph[here][i].second;
                int next = graph[here][i].first;
                if(!visited[next]) {
                    q.push({-nextDist, next});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < M; i++) {
        int from, to, val;
        cin >> from >> to >> val;
        graph[from].push_back({to, val});
        graph[to].push_back({from, val});
    }
    prim();
    cout << totalDist;
    return 0;
}