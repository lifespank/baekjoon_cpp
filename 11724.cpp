#include <iostream>
#include <cstring>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<int> graph[1001];
bool visited[1001];
int totalCount;

void dfs(int start) {
    visited[start] = true;
    for(int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];
        if(!visited[next]) {
            dfs(next);
        }
    }
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    totalCount = 0;
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            totalCount++;
            dfs(i);
        }
    }
    cout << totalCount;

    return 0;
}