#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int minVal = 1e9;

bool isGood(vector<vector<int>>& graph, int area) {
    if (!area) {
        return false;
    }
    int visited = area;
    int i = 0;
    while (!(visited & 1)) {
        visited = visited >> 1;
        i++;
    }
    visited = 1 << i;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        for (auto &next: graph[here]) {
            if (!(visited & (1 << next)) && (area & (1 << next))) {
                visited |= 1 << next;
                q.push(next);
            }
        }
    }
    if (visited == area) {
        return true;
    } else {
        return false;
    }
}

void comb(vector<vector<int>>& graph, vector<int>& population, int area, int idx, int total) {
    if (idx >= graph.size()) {
        return;
    }
    if (isGood(graph, area) && isGood(graph, ~area & (((1 << graph.size()) - 1)) & ~1)) {
        int count = 0;
        for (int i = 1; i < population.size(); i++) {
            if ((1 << i) & area) {
                count += population[i];
            }
        }
        minVal = min(minVal, abs(2 * count - total));
    }
    comb(graph, population, area | (1 << idx), idx + 1, total);
    comb(graph, population, area, idx + 1, total);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> population(N + 1);
    vector<vector<int>> graph(N + 1);
    int total = 0;
    for (int i = 1; i <= N; i++) {
        cin >> population[i];
        total += population[i];
    }
    for (int i = 1; i <= N; i++) {
        int neighbors;
        cin >> neighbors;
        while (neighbors-- > 0) {
            int to;
            cin >> to;
            graph[i].push_back(to);
            graph[to].push_back(i);
        }
    }
    comb(graph, population, 0, 1, total);
    if (minVal == 1e9) {
        minVal = -1;
    }
    cout << minVal;
    return 0;
}