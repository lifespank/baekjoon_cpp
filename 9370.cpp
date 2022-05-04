#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& graph, vector<vector<int>>& dist, int s) {
    vector<int> ans;
    priority_queue<pair<int, int>> pq;
    vector<bool> visitsSmelled(graph.size(), false);
    dist[s][s] = 0;
    pq.push({-dist[s][s], s});
    while (!pq.empty()) {
        int here = pq.top().second;
        pq.pop();
        for (auto &nextNode: graph[here]) {
            int next = nextNode.first;
            int nextWeight = nextNode.second;
            if (dist[s][next] > dist[s][here] + nextWeight) {
                dist[s][next] = dist[s][here] + nextWeight;
                pq.push({-dist[s][next], next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T-- > 0) {
        int n, m, t, s, g, h;
        cin >> n >> m >> t >> s >> g >> h;
        vector<vector<pair<int, int>>> graph(n + 1);
        int smellWeight;
        vector<int> targets(t);
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, 1e9));
        for (int i = 0; i < m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            graph[a].push_back({b, d});
            graph[b].push_back({a, d});
            if (a == g && b == h || a == h && b == g) {
                smellWeight = d;
            }
        }
        for (int i = 0; i < t; i++) {
            cin >> targets[i];
        }
        dijkstra(graph, dist, s);
        dijkstra(graph, dist, g);
        dijkstra(graph, dist, h);
        vector<int> ans;
        for (auto& target: targets) {
            if (dist[s][target] == dist[s][g] + smellWeight + dist[h][target] || dist[s][target] == dist[s][h] + smellWeight + dist[g][target]) {
                ans.push_back(target);
            }
        }
        sort(ans.begin(), ans.end());
        for (auto& an: ans) {
            cout << an << " ";
        }
        cout << "\n";
    }
    return 0;
}