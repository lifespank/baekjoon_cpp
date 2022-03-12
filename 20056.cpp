#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<tuple<int, int, int>> board[51][51];

int N, M, K;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for(int i = 0; i < M; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        board[r][c].push_back({m, s, d});
    }
    queue<pair<pair<int, int>, tuple<int, int, int>>> newBalls;
    for(int k = 0; k < K; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(!board[i][j].empty()) {
                    for(auto it = board[i][j].begin(); it != board[i][j].end(); it++) {
                        int nX = i + (get<1>(*it) % N) * dx[get<2>(*it)];
                        if (nX > N) {
                            nX = nX - N;
                        }
                        if (nX < 1) {
                            nX = N + nX;
                        }
                        int nY = j + (get<1>(*it) % N) * dy[get<2>(*it)];
                        if (nY > N) {
                            nY = nY - N;
                        }
                        if(nY < 1) {
                            nY = N + nY;
                        }
                        newBalls.push({{nX, nY}, *it});
                    }
                    board[i][j].clear();
                }
            }
        }
        while(!newBalls.empty()) {
            board[newBalls.front().first.first][newBalls.front().first.second].push_back(newBalls.front().second);
            newBalls.pop();
        }
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if (board[i][j].size() > 1) {
                    int mSum = 0;
                    int sSum = 0;
                    bool odds = true;
                    bool evens = true;
                    for(auto it = board[i][j].begin(); it != board[i][j].end(); it++) {
                        mSum += get<0>(*it);
                        sSum += get<1>(*it);
                        if (get<2>(*it) % 2 == 0) {
                            odds = false;
                        } else {
                            evens = false;
                        }
                    }
                    int m = mSum / 5;
                    int s = sSum / board[i][j].size();
                    vector<int> dirs;
                    if (odds || evens) {
                        dirs = {0, 2, 4, 6};
                    } else {
                        dirs = {1, 3, 5, 7};
                    }
                    board[i][j].clear();
                    if(m > 0) {
                        for(auto dir = dirs.begin(); dir != dirs.end(); dir++) {
                            board[i][j].push_back({m, s, *dir});
                        }
                    }
                }
            }
        }
    }

    int sum = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if (!board[i][j].empty()) {
                for(auto it = board[i][j].begin(); it != board[i][j].end(); it++) {
                    sum += get<0>(*it);
                }
            }
        }
    }
    
    cout << sum;
    return 0;
}