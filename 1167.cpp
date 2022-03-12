#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

vector<pair<int, int>> tree[100001];
bool visited[100001];
int V;
int maxLong;

void dfs(int start, int depth, int& farPoint) {
    visited[start] = true;
    if(maxLong < depth) {
        maxLong = depth;
        farPoint = start;
    }
    for(int i = 0; i < tree[start].size(); i++) {
        if(!visited[tree[start][i].first]) {
            visited[tree[start][i].first] = true;
            dfs(tree[start][i].first, depth + tree[start][i].second, farPoint);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V;
    for(int i = 0; i < V; i++) {
        int from, to, val;
        cin >> from;
        cin >> to;
        while(to != -1) {
            cin >> val;
            tree[from].push_back({to, val});
            cin >> to;
        }
    }
    int farPoint = 0, realFarPoint = 0;
    dfs(1, 0, farPoint);
    memset(visited, false, sizeof(visited));
    dfs(farPoint, 0, realFarPoint);
    cout << maxLong;
    return 0;
}