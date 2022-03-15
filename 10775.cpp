#include <iostream>

using namespace std;

int findRoot(int *parent, int u) {
    if (parent[u] == u) {
        return u;
    }
    return parent[u] = findRoot(parent, parent[u]);
}

void merge(int *parent, int u, int v) {
    u = findRoot(parent, u);
    v = findRoot(parent, v);
    if (u == v) {
        return;
    }
    parent[u] = v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int G, P;
    cin >> G >> P;
    int *parent = new int[G + 1];
    for (int i = 0; i <= G; i++) {
        parent[i] = i;
    }
    int count = 0;
    bool isDone = false;
    for (int i = 0; i < P; i++) {
        int g;
        cin >> g;
        if (!isDone) {
            g = findRoot(parent, g);
            if (!g) {
                isDone = true;
            } else {
                count++;
                merge(parent, g, g - 1);
            }
        }
    }
    cout << count;
    delete[] parent;
    return 0;
}