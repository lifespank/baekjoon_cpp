#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a[1001];
int N, inDegree[1001], T, K, D[1001], W;

int topologicalSort() {
    int result[1001];
    int time = 0;
    queue<int> q;
    for(int i = 1; i <= N; i++) {
        result[i] = D[i];
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }
    for(int i = 1; i <= N; i++) {
        if(q.empty()) {
            cout << "cycle" << '\n';
            return -1;
        }
        int x = q.front();
        q.pop();
        for(int i = 0; i < a[x].size(); i++) {
            int y = a[x][i];
            result[y] = max(result[y], result[x] + D[y]);
            if(--inDegree[y] == 0) {
                q.push(y);
            }
        }
    }
    return result[W];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for(int tc = 0; tc < T; tc++) {
        memset(inDegree, 0, sizeof(inDegree));
        memset(D, 0, sizeof(D));
        for(int i = 0; i < 1001; i++) {
            a[i].clear();
        }
        cin >> N >> K;
        for(int i = 1; i <= N; i++) {
            cin >> D[i];
        }
        for(int i = 0; i < K; i++) {
            int before, after;
            cin >> before >> after;
            a[before].push_back(after);
            inDegree[after]++;
        }
        cin >> W;
        cout << topologicalSort() << '\n';
    }


    return 0;
}