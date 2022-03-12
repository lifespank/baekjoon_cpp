#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m;
int parent[1000001];
int level[1000001];


int find(int u) {
    if(u == parent[u]) {
        return u;
    }
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) {
        return;
    }
    if(level[u] > level[v]) {
        swap(u, v);
    }
    parent[u] = v;
    if(level[u] == level[v]) {
        level[v]++;
    }
}

bool isSame(int u, int v) {
    if(find(u) == find(v)) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        level[i] = 1;
    }
    for(int i = 0; i < m; i++) {
        int u, v, opr;
        cin >> opr >> u >> v;
        if(opr == 0) {
            merge(u, v);
        }
        else if(opr == 1) {
            if(isSame(u, v)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}