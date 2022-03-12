#include <iostream>
#include <cstring>

using namespace std;

int board[9][9];

bool findUnassigned(int& x, int& y);
bool chkCol(int y, int val);
bool chkRow(int x, int val);
bool chkCube(int x, int y, int val);
bool isSafe(int x, int y, int val);
bool solveSudoku();

int main() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    if(solveSudoku()) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}

bool solveSudoku() {
    int x, y;
    if(!findUnassigned(x, y)) {
        return true;
    }
    for(int num = 1; num <= 9; num++) {
        if(isSafe(x, y, num)) {
            board[x][y] = num;
            
            if(solveSudoku()) {
                return true;
            }
            board[x][y] = 0;
        }
    }
    return false;
}

bool isSafe(int x, int y, int val) {
    return chkCol(y, val) && chkRow(x, val) && chkCube(x, y, val) && board[x][y] == 0;
}

bool findUnassigned(int& x, int& y) {
    for(x = 0; x < 9; x++) {
        for(y = 0; y < 9; y++) {
            if(board[x][y] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool chkCol(int y, int val) {
    for(int i = 0; i < 9; i++) {
        if(board[i][y] == val) {
            return false;
        }
    }
    return true;
}

bool chkRow(int x, int val) {
    for(int i = 0; i < 9; i++) {
        if(board[x][i] == val) {
            return false;
        }
    }
    return true;
}

bool chkCube(int x, int y, int val) {
    int cubeX = x / 3;
    int cubeY = y / 3;
    for(int i = 3 * cubeX; i < 3 * cubeX + 3; i++) {
        for(int j = 3 * cubeY; j < 3 * cubeY + 3; j++) {
            if(board[i][j] == val) {
                return false;
            }
        }
    }
    return true;
}