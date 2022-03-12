#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int N;
char board[50][50];
int dx[2] = {0, 1};
int dy[2] = {1, 0};

bool isInBoard(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int countLong() {
    int ans = 0;
    int rowCount = 0;
    int colCount = 0;
    for(int i = 0; i < N; i++) {
        rowCount = 1;
        colCount = 1;
        for(int j = 1; j < N; j++) {
            if(board[i][j] == board[i][j - 1]) {
                rowCount++;
            }
            else {
                rowCount = 1;
            }
            if(board[j][i] == board[j - 1][i]) {
                colCount++;
            }
            else {
                colCount = 1;
            }
            ans = max({ans, rowCount, colCount});
        }
        
    }
    return ans;
}

int main() {
    scanf("%d", &N);
    getchar();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            board[i][j] = getchar();
        }
        getchar();
    }
    int maxLen = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < 2; k++) {
                int nX = i + dx[k];
                int nY = j + dy[k];
                if(isInBoard(nX, nY) && board[i][j] != board[nX][nY]) {
                    swap(board[i][j], board[nX][nY]);
                    maxLen = max(maxLen, countLong());
                    swap(board[i][j], board[nX][nY]);
                }
            }

        }
    }
    printf("%d", maxLen);
    return 0;
}