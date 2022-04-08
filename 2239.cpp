#include <cstdio>
#include <cstdlib>
#include <utility>

using namespace std;

int board[9][9];
bool rowCheck[10][9];
bool colCheck[10][9];
bool boxCheck[10][9];

void printBoard() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d", board[i][j]);
        }
        printf("\n");
    }
}

pair<int, int> getNewRowCol(int row, int col) {
    col++;
    if (col == 9) {
        col = 0;
        row++;
    }
    return {row, col};
}

bool solve(int row, int col) {
    if (row == 9) {
        printBoard();
        exit(0);
    }
    pair<int, int> newRowCol = getNewRowCol(row, col);
    if (board[row][col]) {
        solve(newRowCol.first, newRowCol.second);
    }
    for (int i = 1; i <= 9; i++) {
        if (!board[row][col] && !colCheck[i][col] && !rowCheck[i][row] && !boxCheck[i][3 * (row / 3) + col / 3]) {
            board[row][col] = i;
            colCheck[i][col] = rowCheck[i][row] = boxCheck[i][3 * (row / 3) + col / 3] = true;
            if (solve(newRowCol.first, newRowCol.second)) {
                return true;
            }
            board[row][col] = 0;
            colCheck[i][col] = rowCheck[i][row] = boxCheck[i][3 * (row / 3) + col / 3] = false;
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i][j] = getchar() - '0';
            if (board[i][j]) {
                colCheck[board[i][j]][j] = rowCheck[board[i][j]][i] = boxCheck[board[i][j]][3 * (i / 3) + j / 3] = true;
            }
        }
        getchar();
    }
    solve(0, 0);
    return 0;
}