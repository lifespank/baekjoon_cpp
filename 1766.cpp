#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> inDegree(n + 1, 0);
    priority_queue<int, vector<int>, greater<int>>pq;
    for (int i = 0; i < m; i++) {
        int to, from;
        cin >> from >> to;
        graph[from].push_back(to);
        inDegree[to]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!inDegree[i]) {
            pq.push(i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (pq.empty()) {
            return 1;
        }
        int num = pq.top();
        pq.pop();
        cout << num << ' ';
        for (int j = 0; j < graph[num].size(); j++) {
            int next = graph[num][j];
            if (--inDegree[next] == 0) {
                pq.push(next);
            }
        }
    }
    return 0;
}