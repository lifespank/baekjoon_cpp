#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph) {
    priority_queue<pair<int, int>> pq;
    vector<int> dist(graph.size(), INF);
    vector<int> rightBefore(graph.size(), 0);
    pq.push({0, 1});
    dist[1] = 0;
    while (!pq.empty()) {
        int here = pq.top().second;
        pq.pop();
        for (auto& nextInfo: graph[here]) {
            int next = nextInfo.first;
            int nextWeight = nextInfo.second;
            if (dist[next] > dist[here] + nextWeight) {
                dist[next] = dist[here] + nextWeight;
                rightBefore[next] = here;
                pq.push({-dist[next], next});
            }
        }
    }
    return rightBefore;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }
    vector<int> rightBefore = dijkstra(graph);
    cout << N - 1 << '\n';
    for (int i = 2; i <= N; i++) {
        cout << i << ' ' << rightBefore[i] << '\n';
    }
    return 0;
}