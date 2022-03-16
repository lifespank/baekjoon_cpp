#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void dfs(vector<vector<int>> &tree, vector<int> &depth, vector<vector<int>> &parent, int here, int dth) {
    depth[here] = dth;
    for (auto &next : tree[here]) {
        if (!depth[next]) {
            parent[0][next] = here;
            dfs(tree, depth, parent, next, dth + 1);
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
    vector<vector<int>> tree(N + 1, vector<int>());
    vector<vector<int>> parent(logMax + 1, vector<int>(N + 1, 0));
    vector<int> depth(N + 1, 0);
    for (int i = 0; i < N - 1; i++) {
        int from, to;
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }
    dfs(tree, depth, parent, 1, 1);
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
        cout << lca(parent, depth, u, v) << '\n';
    }
    return 0;
}