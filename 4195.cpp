#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string findRoot(unordered_map<string, string> &parent, string u) {
    if (parent[u] == u) {
        return u;
    }
    return parent[u] = findRoot(parent, parent[u]);
}

void merge(unordered_map<string, string> &parent, unordered_map<string, int> &level, unordered_map<string, int> &members, string u, string v) {
    u = findRoot(parent, u);
    v = findRoot(parent, v);
    if (u == v) {
        return;
    }
    if (level[u] < level[v]) {
        parent[u] = v;
        members[v] += members[u];
    } else if (level[u] > level[v]) {
        parent[v] = u;
        members[u] += members[v];
    } else {
        parent[u] = v;
        level[v]++;
        members[v] += members[u];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int testCase = 0; testCase < T; testCase++) {
        int F;
        cin >> F;
        unordered_map<string, string> parent;
        unordered_map<string, int> level;
        unordered_map<string, int> members;
        for (int i = 0; i < F; i++) {
            string u, v;
            cin >> u >> v;
            if (parent.find(u) == parent.end()) {
                parent[u] = u;
                level[u] = 1;
                members[u] = 1;
            }
            if (parent.find(v) == parent.end()) {
                parent[v] = v;
                level[v] = 1;
                members[v] = 1;
            }
            merge(parent, level, members, u, v);
            cout << members[findRoot(parent, u)] << '\n';
        }
    }
    return 0;
}