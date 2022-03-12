#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <climits>
#define BIGNUM LLONG_MAX

using namespace std;

long long dijkstra(vector<vector<pair<int, long long>>> graph, int N, int M, int K) {
    vector<vector<long long>> dist(N + 1, vector<long long>(K + 1, BIGNUM));
    dist[1][0] = 0;
    priority_queue<tuple<long long, int, int>> pq;
    pq.push({-dist[1][0], 1, 0});
    while (!pq.empty()) {
        int here = get<1>(pq.top());
        long long distance = -get<0>(pq.top());
        int roadCount = get<2>(pq.top());
        pq.pop();
        if (dist[here][roadCount] < distance) {
            continue;
        }
        for (auto &node : graph[here]) {
            int next = node.first;
            long long nextCost = distance + node.second;
            if (roadCount + 1 <= K && dist[next][roadCount + 1] > distance) {
                dist[next][roadCount + 1] = distance;
                pq.push({-dist[next][roadCount + 1], next, roadCount + 1});
            }
            if (dist[next][roadCount] > nextCost) {
                dist[next][roadCount] = nextCost;
                pq.push({-dist[next][roadCount], next, roadCount});
            }
        }
    }
    long long ans = *min_element(dist[N].begin(), dist[N].end());
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<pair<int, long long>>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int from, to;
        long long val;
        cin >> from >> to >> val;
        graph[from].push_back({to, val});
        graph[to].push_back({from, val});
    }
    cout << dijkstra(graph, N, M, K);
    return 0;
}