#include <iostream>

using namespace std;

void setQueen(int rowNum, int n, int &count, bool colCheck[], bool leftDiagCheck[], bool rightDiagCheck[]) {
    if (rowNum == n) {
        count++;
        return;
    }
    for (int colNum = 0; colNum < n; colNum++) {
        if (!colCheck[colNum] && !leftDiagCheck[rowNum - colNum + n - 1] && !rightDiagCheck[rowNum + colNum]) {
            colCheck[colNum] = leftDiagCheck[rowNum - colNum + n - 1] = rightDiagCheck[rowNum + colNum] = true;
            setQueen(rowNum + 1, n, count, colCheck, leftDiagCheck, rightDiagCheck);
            colCheck[colNum] = leftDiagCheck[rowNum - colNum + n - 1] = rightDiagCheck[rowNum + colNum] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    bool *colCheck = new bool[n]();
    bool *leftDiagCheck = new bool[2 * n - 1]();
    bool *rightDiagCheck = new bool[2 * n - 1]();
    int count = 0;
    setQueen(0, n, count, colCheck, leftDiagCheck, rightDiagCheck);
    cout << count;
    delete[] colCheck;
    delete[] leftDiagCheck;
    delete[] rightDiagCheck;
    return 0;
}