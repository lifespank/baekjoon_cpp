#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <tuple>
#include <memory.h>

using namespace std;

int N, M, T;
int board[51][51];
bool visited[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void turnOne(int x, int d) {
    if (d == 0) {
        int temp = board[x][M - 1];
        for(int i = M - 1; i > 0; i--) {
            board[x][i] = board[x][i - 1];
        }
        board[x][0] = temp;
    } else {
        int temp = board[x][0];
        for(int i = 0; i < M - 1; i++) {
            board[x][i] = board[x][i + 1];
        }
        board[x][M - 1] = temp;
    }
}

void turn(int x, int d, int k) {
    int originX = x;
    while(x <= N) {
        for(int i = 0; i < k; i++) {
            turnOne(x, d);
        }
        x += originX;
    }
}

bool isInBoard(int x) {
    return x >= 1 && x <= N;
}

void bfs(int startX, int startY, queue<tuple<int, int, int>>& newOnes) {
    visited[startX][startY] = true;
    queue<pair<int, int>> q;
    q.push({startX, startY});
    while(!q.empty()) {
        int hereX = q.front().first;
        int hereY = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nX = hereX + dx[i];
            int nY = hereY + dy[i];
            if (nY == M) {
                nY = 0;
            }
            if (nY == -1) {
                nY = M - 1;
            }
            if (isInBoard(nX) && !visited[nX][nY] && board[nX][nY] == board[hereX][hereY]) {
                visited[nX][nY] = true;
                q.push({nX, nY});
                newOnes.push({nX, nY, 0});
                newOnes.push({hereX, hereY, 0});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> T;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    for(int t = 0; t < T; t++) {
        int x, d, k;
        cin >> x >> d >> k;
        turn(x, d, k);
        queue<tuple<int, int, int>> newOnes;
        for(int i = 1; i <= N; i++) {
            for(int j = 0; j < M; j++) {
                if (!visited[i][j] && board[i][j]) {
                    bfs(i, j, newOnes);
                }
            }
        }
        if (newOnes.empty()) {
            int sum = 0;
            int count = 0;
            for(int i = 1; i <= N; i++) {
                for(int j = 0; j < M; j++) {
                    if (board[i][j]) {
                        sum += board[i][j];
                        count++;
                    }
                }
            }
            double avg = sum / (double)count;
            for(int i = 1; i <= N; i++) {
                for(int j = 0; j < M; j++) {
                    if(board[i][j]) {
                        if (board[i][j] > avg) {
                            newOnes.push({i, j, board[i][j] - 1});
                        } else if(board[i][j] < avg) {
                            newOnes.push({i, j, board[i][j] + 1});
                        }
                    }
                }
            }
        }
        while(!newOnes.empty()) {
            board[get<0>(newOnes.front())][get<1>(newOnes.front())] = get<2>(newOnes.front());
            newOnes.pop();
        }
        for(int i = 1; i <= N; i++) {
            memset(visited[i], 0, sizeof(visited[i]));
        }
    }
    int count = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < M; j++) {
            count += board[i][j];
        }
    }
    cout << count;
    return 0;
}