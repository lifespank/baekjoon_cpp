#include <iostream>
#include <queue>
#include <memory.h>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int V, E, K;
vector<int> graph[20001];
bool visited[20001];
int col[20001];

bool isBipartite() {
    memset(col, -1, sizeof(col));
    queue<pair<int, int>> q;
    for(int i = 1; i <= V; i++) {
        if(col[i] == -1) {
            q.push({i, 0});
            col[i] = 0;
            while(!q.empty()) {
                int here = q.front().first;
                int hereColor = q.front().second;
                q.pop();
                for(int j = 0; j < graph[here].size(); j++) {
                    int next = graph[here][j];
                    if(col[next] == hereColor) {
                        return false;
                    }
                    if(col[next] == -1) {
                        col[next] = hereColor ^ 1;
                        q.push({next, col[next]});
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> K;
    for(int i = 0; i < K; i++) {
        cin >> V >> E;
        memset(visited, 0, sizeof(visited));
        memset(graph, 0, sizeof(graph));
        for(int i = 0; i < E; i++) {
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        bool ans = isBipartite();
        if(ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}