#include <stdio.h>
#include <stdlib.h>

void setQueen(int rowNum, int n, int *colCheck, int *leftDiagCheck, int *rightDiagCheck, int *count) {
    if (rowNum == n) {
        (*count)++;
        return;
    }
    for (int colNum = 0; colNum < n; colNum++) {
        if (!colCheck[colNum] && !leftDiagCheck[rowNum - colNum + n - 1] && !rightDiagCheck[rowNum + colNum]) {
            colCheck[colNum] = leftDiagCheck[rowNum - colNum + n - 1] = rightDiagCheck[rowNum + colNum] = 1;
            setQueen(rowNum + 1, n, colCheck, leftDiagCheck, rightDiagCheck, count);
            colCheck[colNum] = leftDiagCheck[rowNum - colNum + n - 1] = rightDiagCheck[rowNum + colNum] = 0;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *colCheck = (int *)malloc(sizeof(int) * n);
    int *leftDiagCheck = (int *)malloc(sizeof(int) * (2 * n - 1));
    int *rightDiagCheck = (int *)malloc(sizeof(int) * (2 * n - 1));
    int count = 0;
    setQueen(0, n, colCheck, leftDiagCheck, rightDiagCheck, &count);
    printf("%d", count);
    return 0;
}