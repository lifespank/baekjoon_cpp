#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, Q;
int board[65][65];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int length;
int iceLeft = 0;
bool isVisited[65][65];
int maxIce = -1;


bool isInBoard(int x, int y) {
    return x >= 0 && x < length && y >= 0 && y < length;
}

int power_two(int n) {
    if(n == 0) {
        return 1;
    }
    if(n == 1) {
        return 2;
    }
    if(n & 1) {
        return 2 * power_two(n - 1);
    } else {
        int half = power_two(n / 2);
        return half * half;
    }
}

void rotateSmall(int x, int y, int smallLength) {
    vector<vector<int>> temp(smallLength, vector<int>(smallLength, 0));
    for(int i = x; i < x + smallLength; i++) {
        for(int j = y; j < y + smallLength; j++) {
            temp[i - x][j - y] = board[i][j];
        }
    }
    for(int i = y + smallLength - 1; i >= y; i--) {
        for(int j = x; j < x + smallLength; j++) {
            board[j][i] = temp[y + smallLength - 1 - i][j - x];
        }
    }
}

void rotate(int L) {
    int smallLength = power_two(L);
    for(int i = 0; i < length; i += smallLength) {
        for(int j = 0; j < length; j += smallLength) {
            rotateSmall(i, j, smallLength);
        }
    }
}

bool isGoodToMelt(int x, int y) {
    int count = 0;
    for(int i = 0; i < 4; i++) {
        int nX = x + dx[i];
        int nY = y + dy[i];
        if(isInBoard(nX, nY) && board[nX][nY]) {
            count++;
        }
    }
    if (count < 3) {
        return true;
    }
    return false;
}

void melt() {
    queue<pair<int, int>> toMelt;
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            if(isGoodToMelt(i, j)) {
                toMelt.push({i, j});
            }
        }
    }
    while(!toMelt.empty()) {
        int x = toMelt.front().first;
        int y = toMelt.front().second;
        if (board[x][y] > 0) {
            board[x][y]--;
        }
        toMelt.pop();
    }
}

void bfs(int startX, int startY) {
    isVisited[startX][startY] = true;
    queue<pair<int, int>> q;
    q.push({startX, startY});
    int count = 0;
    int iceCount = 0;
    while(!q.empty()) {
        int hereX = q.front().first;
        int hereY = q.front().second;
        q.pop();
        count++;
        iceCount += board[hereX][hereY];
        for(int i = 0; i < 4; i++) {
            int nX = hereX + dx[i];
            int nY = hereY + dy[i];
            if(isInBoard(nX, nY) && !isVisited[nX][nY] && board[nX][nY]) {
                isVisited[nX][nY] = true;
                q.push({nX, nY});
            }
        }
    }
    maxIce = max(count, maxIce);
    iceLeft += iceCount;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    length = power_two(N);
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < Q; i++) {
        int L;
        cin >> L;
        rotate(L);
        melt();
    }
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            if(!isVisited[i][j] && board[i][j]) {
                bfs(i, j);
            }
        }
    }
    if(maxIce < 0) {
        maxIce = 0;
    }
    cout << iceLeft << '\n' << maxIce;


    return 0;
}