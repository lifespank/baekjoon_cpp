#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int manhattanDistance(int r1, int c1, int r2, int c2) {
    return abs(r1 - r2) + abs(c1 - c2);
}

int kill(vector<pair<int, int>>& archers, vector<pair<int, int>>& enemies, int d) {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, d;
    cin >> n >> m >> d;
    vector<pair<int, int>> enemies;
    vector<pair<int, int>> archers;
    for(int i = 0; i < m; i++) {
        archers.push_back({n + 1, i});
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            if (temp) {
                enemies.push_back({i, j});
            }
        }
    }

    return 0;
}