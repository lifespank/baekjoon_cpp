#include <iostream>
#include <bits/stdc++.h>
#include <memory.h>
#include <vector>

using namespace std;

int N, L;
int board[100][100];


vector<int> makeVector(int lineNum, bool isRow) {
    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        if(isRow) {
            v[i] = board[lineNum][i];
        }
        else {
            v[i] = board[i][lineNum];
        }
    }
    return v;
}

bool lineIsGood(vector<int> v) {
    bool * rampExists = new bool[N];
    memset(rampExists, 0, sizeof(rampExists));
    for(int i = 1; i < N; i++) {
        if(abs(v[i] - v[i - 1]) > 1) {
            return false;
        }
        if(abs(v[i] - v[i - 1]) == 1) {
            if(v[i] > v[i - 1]) {
                for(int j = i - L; j < i; j++) {
                    if(j < 0 || v[j] != v[i - 1] || rampExists[j]) {
                        return false;
                    }
                }
                for(int j = i - L; j < i; j++) {
                    rampExists[j] = true;
                }
            }
            else {
                for(int j = i; j < i + L; j++) {
                    if(j >= N || v[j] != v[i] || rampExists[j]) {
                        return false;
                    }
                }
                for(int j = i; j < i + L; j++) {
                    rampExists[j] = true;
                }
            }
        }
    }
    delete[] rampExists;
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> L;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    int count = 0;
    for(int i = 0; i < N; i++) {
        if(lineIsGood(makeVector(i, true))) {
            count++;
        }
        if(lineIsGood(makeVector(i, false))) {
            count++;
        }
    }
    cout << count;
    return 0;
}