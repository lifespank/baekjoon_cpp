#include <iostream>
#include <vector>

using namespace std;

void dfs(int start, vector<vector<pair<int, int>>> &graph, vector<bool> &visited, int depth, int &maxLen, int &furthest) {
    visited[start] = true;
    if (depth > maxLen) {
        maxLen = depth;
        furthest = start;
    }
    for (auto it = graph[start].begin(); it != graph[start].end(); it++) {
        if (!visited[it->first]) {
            dfs(it->first, graph, visited, depth + it->second, maxLen, furthest);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    for (int i = 0; i < n - 1; i++) {
        int from, to, val;
        cin >> from >> to >> val;
        graph[from].push_back({to, val});
        graph[to].push_back({from, val});
    }
    int t = 1;
    int maxLen = 0;
    dfs(1, graph, visited, 0, maxLen, t);
    int v = 1;
    maxLen = 0;
    fill(visited.begin(), visited.end(), false);
    dfs(t, graph, visited, 0, maxLen, v);
    cout << maxLen;
    return 0;
}