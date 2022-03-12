#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int board[101][101];
int r, c, k;
int rowSize = 3, colSize = 3;

int oneRow(int rowNum) {
    map<int, int> bindo;
    for(int i = 0; i < colSize; i++) {
        if(board[rowNum][i]) {
            bindo[board[rowNum][i]]++;
        }
    }
    vector<pair<int, int>> v;
    for(auto it = bindo.begin(); it != bindo.end(); it++) {
        v.push_back({it->second, it->first});
    }
    //빈도, 숫자
    sort(v.begin(), v.end());
    for(int i = 0; i < colSize; i++) {
        board[rowNum][i] = 0;
    }
    for(int i = 0; i < v.size() && i < 50; i++) {
        board[rowNum][2 * i] = v[i].second;
        board[rowNum][2 * i + 1] = v[i].first;
    }
    return min((int)v.size() * 2, 100);
}

void doRow() {
    int maxVal = 0;
    for(int i = 0; i < rowSize; i++) {
        maxVal = max(maxVal, oneRow(i));
    }
    colSize = maxVal;
}

int oneCol(int colNum) {
    map<int, int> bindo;
    for(int i = 0; i < rowSize; i++) {
        if(board[i][colNum]) {
            bindo[board[i][colNum]]++;
        }
    }
    vector<pair<int, int>> v;
    for(auto it = bindo.begin(); it != bindo.end(); it++) {
        v.push_back({it->second, it->first});
    }
    //빈도, 숫자
    sort(v.begin(), v.end());
    for(int i = 0; i < rowSize; i++) {
        board[i][colNum] = 0;
    }
    for(int i = 0; i < v.size() && i < 50; i++) {
        board[2 * i][colNum] = v[i].second;
        board[2 * i + 1][colNum] = v[i].first;
    }
    return min((int)v.size() * 2, 100);
}

void doCol() {
    int maxVal = 0;
    for(int i = 0; i < colSize; i++) {
        maxVal = max(maxVal, oneCol(i));
    }
    rowSize = maxVal;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c >> k;
    r--;
    c--;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> board[i][j];
        }
    }
    int t = 0;
    for(t = 0; t <= 100; t++) {
        if(board[r][c] == k) {
            break;
        }
        if (rowSize >= colSize) {
            doRow();
        } else {
            doCol();
        }
    }

    if(t > 100) {
        t = -1;
    }

    cout << t;

    return 0;
}