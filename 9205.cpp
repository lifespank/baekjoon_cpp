#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int manhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

bool bfs(vector<vector<int>> &graph) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        if (here == graph.size() - 1) {
            return true;
        }
        for (auto &next : graph[here]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        vector<pair<int, int>> nodes(n + 2);
        vector<vector<int>> graph(n + 2);
        for (int i = 0; i < n + 2; i++) {
            int x, y;
            cin >> x >> y;
            nodes[i] = {x, y};
        }
        for (int i = 0; i < nodes.size() - 1; i++) {
            for (int j = i + 1; j < nodes.size(); j++) {
                if (manhattanDistance(nodes[i].first, nodes[i].second, nodes[j].first, nodes[j].second) <= 1000) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        if (bfs(graph)) {
            cout << "happy\n";
        } else {
            cout << "sad\n";
        }
    }
    return 0;
}