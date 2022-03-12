#include <iostream>
#include <bits/stdc++.h>
#include <deque>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;
int N, M, K;
int A[10][10];
int board[10][10];
deque<tuple<int, int, int>> trees;
queue<tuple<int, int, int>> deadTrees;
queue<pair<int, int>> mulTrees;
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

bool isInBoard(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

void spring() {
    int n = trees.size();
    for(int i = 0; i < n; i++) {
        tuple<int, int, int> tree = trees.front();
        trees.pop_front();
        if(board[get<1>(tree)][get<2>(tree)] >= get<0>(tree)) {
            board[get<1>(tree)][get<2>(tree)] -= get<0>(tree);
            get<0>(tree)++;
            trees.push_back(tree);
            if(get<0>(tree) % 5 == 0) {
                mulTrees.push({get<1>(tree), get<2>(tree)});
            }
        } else {
            deadTrees.push(tree);
        }
    }
}

void summer() {
    while(!deadTrees.empty()) {
        board[get<1>(deadTrees.front())][get<2>(deadTrees.front())] += get<0>(deadTrees.front()) / 2;
        deadTrees.pop();
    }
}

void fall() {
    while(!mulTrees.empty()) {
        for(int i = 0; i < 8; i++) {
            int nX = mulTrees.front().first + dx[i];
            int nY = mulTrees.front().second + dy[i];
            if(isInBoard(nX, nY)) {
                trees.push_front({1, nX, nY});
            }
        }
        mulTrees.pop();
    }
}

void winter() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            board[i][j] += A[i][j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> A[i][j];
            board[i][j] = 5;
        }
    }
    for(int i = 0; i < M; i++) {
        int x, y, age;
        cin >> x >> y >> age;
        trees.push_back({age, x - 1, y - 1});
    }
    sort(trees.begin(), trees.end());
    for(int i = 0; i < K; i++) {
        spring();
        summer();
        fall();
        winter();
    }
    cout << trees.size();
    
    return 0;
}