#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int N;
int board[500][500];
int outSand = 0;

bool isInBoard(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}


int blow(int x, int y, int sand, int percentage) {
    if(isInBoard(x, y)) {
        board[x][y] += sand * percentage / 100;
    } else {
        outSand += sand * percentage / 100;
    }
    return sand * percentage / 100;
}

void wind(int x, int y, int dir, int sand) {
    vector<int> perpenDirs;
    int revDir = (dir + 2) % 4;
    if(dir % 2 == 0){
        perpenDirs = {1, 3};
    } else {
        perpenDirs = {0, 2};
    }
    int ffX = x + dx[dir];
    int ffY = y + dy[dir];
    int usedSand = 0;
    int fX = ffX + dx[dir];
    int fY = ffY + dy[dir];
    usedSand += blow(fX, fY, sand, 5);
    for(auto perpenDir = perpenDirs.begin(); perpenDir != perpenDirs.end(); perpenDir++) {
        int tX = ffX + dx[*perpenDir];
        int tY = ffY + dy[*perpenDir];
        usedSand += blow(tX, tY, sand, 10);
        int sX = tX + dx[revDir];
        int sY = tY + dy[revDir];
        usedSand += blow(sX, sY, sand, 7);
        int twX = sX + dx[*perpenDir];
        int twY = sY + dy[*perpenDir];
        usedSand += blow(twX, twY, sand, 2);
        int oX = sX + dx[revDir];
        int oY = sY + dy[revDir];
        usedSand += blow(oX, oY, sand, 1);
    }
    if(isInBoard(ffX, ffY)) {
        board[ffX][ffY] += sand - usedSand;
    } else {
        outSand += sand - usedSand;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    int n = (N - 1) / 2;
    vector<int> moves;
    for(int i = 1; i <= n; i++) {
        moves.push_back(0);
        for(int j = 0; j < 2 * i - 1; j++) {
            moves.push_back(1);
        }
        for(int j = 0; j < 2 * i; j++) {
            moves.push_back(2);
        }
        for(int j = 0; j < 2 * i; j++) {
            moves.push_back(3);
        }
        for(int j = 0; j < 2 * i; j++) {
            moves.push_back(0);
        }
    }
    int x = n;
    int y = n;
    for(auto move = moves.begin(); move != moves.end(); move++) {
        x += dx[*move];
        y += dy[*move];
        if(board[x][y]) {
            wind(x, y, *move, board[x][y]);
        }
        board[x][y] = 0;
    }
    
    cout << outSand;

    return 0;
}