#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int num, stack<int>& stk, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[num] = true;
    for (int i = 0; i < graph[num].size(); i++) {
        int next = graph[num][i];
        if (!visited[next]) {
            dfs(next, stk, graph, visited);
        }
    }
    stk.push(num);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    stack<int> stk;
    vector<bool> visited(n + 1, false);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, stk, graph, visited);
        }
    }
    while (!stk.empty()) {
        cout << stk.top() << ' ';
        stk.pop();
    }
    return 0;
}