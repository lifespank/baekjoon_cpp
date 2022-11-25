#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool rowCheck[9][10];
bool colCheck[9][10];
bool boxCheck[9][10];
bool dominoCheck[36];
int board[9][9];
int dominoMap[10][10];
int dx[2] = {1, 0};
int dy[2] = {0, 1};

bool isInBoard(int x, int y) {
    return x >= 0 && x < 9 && y >= 0 && y < 9;
}

pair<int, int> getNextPos(int x, int y) {
    x++;
    if (x == 9) {
        x = 0;
        y++;
    }
    return {x, y};
}

bool solve(int x, int y) {
    if (y == 9) {
        return true;
    }
    pair<int, int> nextPos = getNextPos(x, y);
    if (!board[x][y]) {
        for (int i = 1; i <= 9; i++) {
            if (!rowCheck[x][i] && !colCheck[y][i] && !boxCheck[x / 3 * 3 + y / 3][i]) {
                rowCheck[x][i] = colCheck[y][i] = boxCheck[x / 3 * 3 + y / 3][i] = true;
                board[x][y] = i;
                for (int j = 0; j < 2; j++) {
                    int nextX = x + dx[j];
                    int nextY = y + dy[j];
                    for (int k = 1; k <= 9; k++) {
                        if (i == k) {
                            continue;
                        }
                        if (!board[nextX][nextY] && !dominoCheck[dominoMap[i][k]] && !rowCheck[nextX][k] && !colCheck[nextY][k] && !boxCheck[nextX / 3 * 3 + nextY / 3][k]) {
                            dominoCheck[dominoMap[i][k]] = rowCheck[nextX][k] = colCheck[nextY][k] = boxCheck[nextX / 3 * 3 + nextY / 3][k] = true;
                            board[nextX][nextY] = k;
                            if (solve(nextPos.first, nextPos.second)) {
                                return true;
                            }
                            dominoCheck[dominoMap[i][k]] = rowCheck[nextX][k] = colCheck[nextY][k] = boxCheck[nextX / 3 * 3 + nextY / 3][k] = false;
                            board[nextX][nextY] = 0;
                        }
                    }
                }
                rowCheck[x][i] = colCheck[y][i] = boxCheck[x / 3 * 3 + y / 3][i] = false;
                board[x][y] = 0;
            }
        }
        return false;
    } else if (solve(nextPos.first, nextPos.second)) {
        return true;
    }
    return false;
}

pair<int, int> getPos(string pos) {
    return {pos[0] - 'A', pos[1] - '1'};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int dominoIdx = 0;
    for (int i = 1; i < 9; i++) {
        for (int j = i + 1; j <= 9; j++) {
            dominoMap[i][j] = dominoMap[j][i] = dominoIdx;
            dominoIdx++;
        }
    }
    int N;
    cin >> N;
    int tc = 1;
    while (N) {
        memset(rowCheck, false, sizeof(rowCheck));
        memset(colCheck, false, sizeof(colCheck));
        memset(boxCheck, false ,sizeof(boxCheck));
        memset(dominoCheck, false, sizeof(dominoCheck));
        memset(board, 0, sizeof(board));
        for (int i = 0; i < N; i++) {
            string pos[2];
            pair<int, int> realPos[2];
            int num[2];
            cin >> num[0] >> pos[0] >> num[1] >> pos[1];
            for (int j = 0; j < 2; j++) {
                realPos[j] = getPos(pos[j]);
                board[realPos[j].first][realPos[j].second] = num[j];
                rowCheck[realPos[j].first][num[j]] = colCheck[realPos[j].second][num[j]] = boxCheck[realPos[j].first / 3 * 3 + realPos[j].second / 3][num[j]] = true;
            }
            dominoCheck[dominoMap[num[0]][num[1]]] = true;
        }
        for (int i = 1; i <= 9; i++) {
            string pos;
            cin >> pos;
            pair<int, int> realPos = getPos(pos);
            board[realPos.first][realPos.second] = i;
            rowCheck[realPos.first][i] = colCheck[realPos.second][i] = boxCheck[realPos.first / 3 * 3 + realPos.second / 3][i] = true;
        }
        if (solve(0, 0)) {
            cout << "Puzzle " << tc << "\n";
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    cout << board[i][j];
                }
                cout << "\n";
            }
        }
        cin >> N;
        tc++;
    }
    return 0;
}