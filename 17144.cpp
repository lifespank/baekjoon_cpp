#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int R, C, T;
int A[51][51];
int dA[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> airCon;

bool isInBoard(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

void spread(int x, int y) {
    int spreadCount = 0;
    for(int i = 0; i < 4; i++) {
        int nX = x + dx[i];
        int nY = y + dy[i];
        if (isInBoard(nX, nY) && A[nX][nY] != -1) {
            dA[nX][nY] += A[x][y] / 5;
            spreadCount++;
        }
    }
    dA[x][y] -= A[x][y] / 5 * spreadCount;
}

void move() {
    queue<tuple<int, int, int>> q;
    for(int i = 1; i < C; i++) {
        q.push({0, i - 1, A[0][i]});
        q.push({R - 1, i - 1, A[R - 1][i]});
    }
    for(int i = 1; i <= C - 1; i++) {
        q.push({airCon[0], i + 1, A[airCon[0]][i]});
        q.push({airCon[1], i + 1, A[airCon[1]][i]});
    }
    for(int i = 1; i <= airCon[0] - 1; i++) {
        q.push({i, 0, A[i - 1][0]});
    }
    for(int i = 0; i <= airCon[0] - 1; i++) {
        q.push({i, C - 1, A[i + 1][C - 1]});
    }
    for(int i = airCon[1] + 1; i <= R - 2; i++){
        q.push({i, 0, A[i + 1][0]});
    }
    for(int i = airCon[1] +1; i <= R - 1; i++) {
        q.push({i, C - 1, A[i - 1][C - 1]});
    }
    while(!q.empty()) {
        tuple<int, int, int> trip = q.front();
        q.pop();
        A[get<0>(trip)][get<1>(trip)] = get<2>(trip);
    }
    A[airCon[0]][1] = 0;
    A[airCon[1]][1] = 0;
}

int totalDust() {
    int total = 0;
    for(int i = 0; i < R; i++) {
        for(int j = 0 ; j < C; j++){
            if(A[i][j] != -1) {
                total += A[i][j];
            }
        }
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j <C; j++) {
            cin >> A[i][j];
            if (A[i][j] == -1) {
                airCon.push_back(i);
            }
        }
    }
    for (int second = 0; second < T; second++) {
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                spread(i, j);
            }
        }
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                A[i][j] += dA[i][j];
                dA[i][j] = 0;
            }
        }
        move();
    }
    cout << totalDust();
    return 0;
}
