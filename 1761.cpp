#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void dfs(vector<vector<pair<int, long long>>> &tree, vector<int> &depth, vector<vector<int>> &parent, vector<int> &distance, int here, int dth) {
    depth[here] = dth;
    for (auto &next : tree[here]) {
        if (!depth[next.first]) {
            parent[0][next.first] = here;
            distance[next.first] = distance[here] + next.second;
            dfs(tree, depth, parent, distance, next.first, dth + 1);
        }
    }
}

int lca(vector<vector<int>> &parent, vector<int> &depth, int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    int l = depth[u] - depth[v];
    for (int i = parent.size() - 1; i >= 0; i--) {
        if (l & (1 << i)) {
            u = parent[i][u];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = parent.size() - 1; i >= 0; i--) {
        if (parent[i][u] != parent[i][v]) {
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N;
    int logMax = log2(N) + 1;
    vector<vector<pair<int, long long>>> tree(N + 1, vector<pair<int, long long>>());
    vector<vector<int>> parent(logMax + 1, vector<int>(N + 1, 0));
    vector<int> depth(N + 1, 0);
    vector<int> distance(N + 1, 0);
    for (int i = 0; i < N - 1; i++) {
        int from, to;
        long long val;
        cin >> from >> to >> val;
        tree[from].push_back({to, val});
        tree[to].push_back({from, val});
    }
    dfs(tree, depth, parent, distance, 1, 1);
    for (int k = 1; k <= logMax; k++) {
        for (int i = 1; i <= N; i++) {
            if (1 <= parent[k - 1][i] && parent[k - 1][i] <= N) {
                parent[k][i] = parent[k - 1][parent[k - 1][i]];
            }
        }
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        cout << distance[u] + distance[v] - 2 * distance[lca(parent, depth, u, v)] << '\n';
    }
    return 0;
}