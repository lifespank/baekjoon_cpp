#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[101];
int depth[101];
int n;
int m;

int bfs(int start, int end) {
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        for(int i = 0; i < graph[here].size(); i++) {
            int next = graph[here][i];
            if(next == end) {
                return depth[here] + 1;
            }
            if(depth[next] == 0) {
                depth[next] = depth[here] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int start, end;
    cin >> start >> end;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    cout << bfs(start, end);
    return 0;
}