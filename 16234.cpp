#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <memory.h>
#include <cmath>

using namespace std;

int N, L, R;
int board[51][51];
int tempBoard[51][51];
bool isVisited[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool isInBoard(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool isOpen(int hereX, int hereY, int nX, int nY) {
    int diff = abs(board[hereX][hereY] - board[nX][nY]);
    if(L <= diff && diff <= R) {
        return true;
    }
    return false;
}

bool bfs(int x, int y) {
    vector<vector<bool>> isVisitedHere(N, (vector<bool>(N, false)));
    int countries = 1;
    int people = board[x][y];
    isVisited[x][y] = true;
    queue<pair<int, int>> q;
    queue<pair<int, int>> visitedCountries;
    q.push({x, y});
    while(!q.empty()) {
        int hereX = q.front().first;
        int hereY = q.front().second;
        visitedCountries.push({hereX, hereY});
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nX = hereX + dx[i];
            int nY = hereY + dy[i];
            if(isInBoard(nX, nY) && !isVisited[nX][nY] && isOpen(hereX, hereY, nX, nY)) {
                isVisited[nX][nY] = true;
                q.push({nX, nY});
                countries++;
                people += board[nX][nY];
            }
        }
    }
    while(!visitedCountries.empty()) {
        tempBoard[visitedCountries.front().first][visitedCountries.front().second] = people / countries;
        visitedCountries.pop();
    }
    if(countries == 1) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> L >> R;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    int days = -1;
    int single;
    do {
        single = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(!isVisited[i][j] && bfs(i, j)) {
                    single++;
                }
            }
        }
        memset(isVisited, 0, sizeof(isVisited));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                board[i][j] = tempBoard[i][j];
            }
        }
        days++;
    } while(single < N * N);
    cout << days;
    return 0;
}