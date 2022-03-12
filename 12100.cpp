#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int maxVal = 0;

void printBoard(vector<vector<int>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void dequeInsert(deque<pair<int, bool>> &deq, int num) {
    if (num > 0) {
        if (deq.empty()) {
            deq.push_back({num, false});
        } else if (!deq.back().second && deq.back().first == num) {
            deq.pop_back();
            deq.push_back({num << 1, true});
        } else {
            deq.push_back({num, false});
        }
    }
}

vector<vector<int>> moveUp(vector<vector<int>> board) {
    for (int col = 0; col < board[0].size(); col++) {
        deque<pair<int, bool>> deq;
        for (int row = 0; row < board.size(); row++) {
            dequeInsert(deq, board[row][col]);
        }
        for (int row = 0; row < board.size(); row++) {
            if (!deq.empty()) {
                board[row][col] = deq.front().first;
                deq.pop_front();
            } else {
                board[row][col] = 0;
            }
        }
    }
    return board;
}

vector<vector<int>> moveDown(vector<vector<int>> board) {
    for (int col = 0; col < board[0].size(); col++) {
        deque<pair<int, bool>> deq;
        for (int row = board.size() - 1; row >= 0; row--) {
            dequeInsert(deq, board[row][col]);
        }
        for (int row = board.size() - 1; row >= 0; row--) {
            if (!deq.empty()) {
                board[row][col] = deq.front().first;
                deq.pop_front();
            } else {
                board[row][col] = 0;
            }
        }
    }
    return board;
}

vector<vector<int>> moveRight(vector<vector<int>> board) {
    for (int row = 0; row < board.size(); row++) {
        deque<pair<int, bool>> deq;
        for (int col = board[row].size() - 1; col >= 0; col--) {
            dequeInsert(deq, board[row][col]);
        }
        for (int col = board[row].size() - 1; col >= 0; col--) {
            if (!deq.empty()) {
                board[row][col] = deq.front().first;
                deq.pop_front();
            } else {
                board[row][col] = 0;
            }
        }
    }
    return board;
}

vector<vector<int>> moveLeft(vector<vector<int>> board) {
    for (int row = 0; row < board.size(); row++) {
        deque<pair<int, bool>> deq;
        for (int col = 0; col < board[row].size() ; col++) {
            dequeInsert(deq, board[row][col]);
        }
        for (int col = 0; col < board[row].size() ; col++) {
            if (!deq.empty()) {
                board[row][col] = deq.front().first;
                deq.pop_front();
            } else {
                board[row][col] = 0;
            }
        }
    }
    return board;
}

void findMax(vector<vector<int>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            maxVal = max(maxVal, board[i][j]);
        }
    }
}

void solve(vector<vector<int>> &board, int depth) {
    if (depth == 5) {
        findMax(board);
        return;
    }
    for (int i = 0; i < 4; i++) {
        vector<vector<int>> newBoard;
        switch(i) {
            case 0:
            newBoard = moveUp(board);
            break;
            case 1:
            newBoard = moveRight(board);
            break;
            case 2:
            newBoard = moveDown(board);
            break;
            case 3:
            newBoard = moveLeft(board);
            break;
            default:
            break;
        }
        solve(newBoard, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    solve(board, 0);
    cout << maxVal;
    return 0;
}