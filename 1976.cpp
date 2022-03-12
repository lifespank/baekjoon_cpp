#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int parent[201];
int level[201];
int N, M;

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
    return find(u) == find(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin >> M;
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
        level[i] = 1;
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int connected;
            cin >> connected;
            if(connected) {
                merge(i, j);
            }
        }
    }
    int prev, curr;
    int i = 0;
    for(i = 0; i < M; i++) {
        if(i == 0) {
            cin >> prev;
            continue;
        }
        cin >> curr;
        if(!isSame(prev, curr)) {
            break;
        }
        prev = curr;
    }
    if(i == M || M == 1) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}
