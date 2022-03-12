#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

int board[50][50];
int depth[50][50];
int N, M;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int emptyCount = 0;
vector<pair<int, int>> virusPlace;

bool isInBoard(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int bfs(vector<pair<int, int>>& selected) {
    int infested = 0;
    for(int i = 0; i < N; i++) {
        memset(depth[i], -1, sizeof(depth[i]));
    }
    queue<pair<int, int>> q;
    for(int i = 0; i < selected.size(); i++) {
        depth[selected[i].first][selected[i].second] = 0;
        q.push({selected[i].first, selected[i].second});
    }
    while(!q.empty()) {
        int hereX = q.front().first;
        int hereY = q.front().second;
        q.pop();
        if (!board[hereX][hereY]) {
            infested++;
        }
        if (infested == emptyCount) {
            return depth[hereX][hereY];
        }
        for(int i = 0; i < 4; i++) {
            int nX = hereX + dx[i];
            int nY = hereY + dy[i];
            if(isInBoard(nX, nY) && depth[nX][nY] == -1 && board[nX][nY] != 1) {
                depth[nX][nY] = depth[hereX][hereY] + 1;
                q.push({nX, nY});
            }
        }
    }
    return 1e9;
}

int comb() {
    int minTime = 1e9;
    vector<int> ind;
    for(int i = 0; i < virusPlace.size() - M; i++) {
        ind.push_back(0);
    }
    for(int i = 0; i < M; i++) {
        ind.push_back(1);
    }
    vector<pair<int, int>> selected;
    do {
        for(int i = 0; i < ind.size(); i++) {
            if(ind[i]) {
                selected.push_back(virusPlace[i]);
            }
        }
        minTime = min(minTime, bfs(selected));
        selected.clear();
    }while(next_permutation(ind.begin(), ind.end()));
    if(minTime == 1e9) {
        minTime = -1;
    }
    return minTime;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                virusPlace.push_back({i, j});
            } else if (!board[i][j]) {
                emptyCount++;
            }
        }
    }

    cout << comb();
    
    return 0;
}