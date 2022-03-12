#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
bool board[101][101];
int N;

void nextGenDir(vector<int>& dirs) {
    vector<int> after;
    if(dirs.size() > 1) {
        for(int i = 0; i < dirs.size() / 2; i++) {
            after.push_back((dirs[i] + 2) % 4);
        }
        for(int i = dirs.size() / 2; i < dirs.size(); i++) {
            after.push_back(dirs[i]);
        }
    } else {
        after.push_back((dirs[0] + 1) % 4);
    }
    for(int i = 0; i < after.size(); i++) {
        dirs.push_back(after[i]);
    }
}

int count() {
    int total = 0;
    for(int i = 0; i <= 99; i++) {
        for(int j = 0; j <= 99; j++) {
            if(board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) {
                total++;
            }
        }
    }
    return total;
}

void draw(int x, int y, int targetG, int nowG, vector<int>& dirs) {
    if(targetG == nowG) {
        return;
    }
    board[x][y] = true;
    int nX = x;
    int nY = y;
    for(int i = dirs.size() / 2; i < dirs.size(); i++) {
        nX += dx[dirs[i]];
        nY += dy[dirs[i]];
        board[nX][nY] = true;
    }
    nextGenDir(dirs);
    draw(nX, nY, targetG, nowG + 1, dirs);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        int x, y, d, g;
        cin >> y >> x >> d >> g;
        vector<int> dirs = {d};
        draw(x, y, g, -1, dirs);
    }
    cout << count();
    return 0;
}