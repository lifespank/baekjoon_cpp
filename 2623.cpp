#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1);
    vector<int> inDegree(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int singerCount;
        cin >> singerCount;
        int from, to;
        cin >> from;
        while (singerCount-- > 1) {
            cin >> to;
            graph[from].push_back(to);
            inDegree[to]++;
            from = to;
        }
    }
    queue<int> q;
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        if (!inDegree[i]) {
            q.push(i);
        }
    }
    for (int i = 1; i <= N; i++) {
        if (q.empty()) {
            ans.clear();
            ans.push_back(0);
            break;
        }
        int num = q.front();
        q.pop();
        ans.push_back(num);
        for (int j = 0; j < graph[num].size(); j++) {
            int next = graph[num][j];
            if (--inDegree[next] == 0) {
                q.push(next);
            }
        }
    }
    for (auto &num : ans) {
        cout << num << '\n';
    }
    return 0;
}