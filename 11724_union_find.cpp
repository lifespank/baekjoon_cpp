#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int findRoot(vector<int> &parent, int u) {
    if (u == parent[u]) {
        return u;
    }
    return parent[u] = findRoot(parent, parent[u]);
}

void merge(vector<int> &parent, vector<int> &level, int u, int v) {
    u = findRoot(parent, u);
    v = findRoot(parent, v);
    if (u == v) {
        return;
    }
    if (level[u] < level[v]) {
        parent[u] = v;
    } else if (level[u] > level[v]) {
        parent[v] = u;
    } else {
        parent[u] = v;
        level[v]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<int> parent(N + 1);
    vector<int> level(N + 1, 1);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        merge(parent, level, from, to);
    }
    unordered_set<int> roots;
    for (int i = 1; i <= N; i++) {
        roots.insert(findRoot(parent, i));
    }
    cout << roots.size();
    return 0;
}