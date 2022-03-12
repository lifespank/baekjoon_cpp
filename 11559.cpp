#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isInBoard(int x, int y) {
    return x >= 0 && x < 12 && y >= 0 && y < 6;
}

void fall(vector<vector<char>> &board) {
    queue<char> q;
    for(int j = 0; j < 6; j++) {
        for(int i = 11; i >= 0; i--) {
            if (board[i][j] != '.') {
                q.push(board[i][j]);
            }
        }
        for(int i = 11; i >= 0; i--) {
            if (!q.empty()) {
                board[i][j] = q.front();
                q.pop();
            } else {
                board[i][j] = '.';
            }
        }
    }
}

int bfs(vector<vector<char>> &board, int x, int y) {
    queue<pair<int, int>> q;
    queue<pair<int ,int>> candidate;
    bool visited[12][6] = {false};
    q.push({x, y});
    candidate.push({x, y});
    visited[x][y] = true;
    while(!q.empty()) {
        int hereX = q.front().first;
        int hereY = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nX = hereX + dx[i];
            int nY = hereY + dy[i];
            if(isInBoard(nX, nY) && !visited[nX][nY] && board[x][y] == board[nX][nY]) {
                q.push({nX, nY});
                candidate.push({nX, nY});
                visited[nX][nY] = true;
            }
        }
    }
    int popped = candidate.size();
    if (popped < 4) {
        popped = 0;
    }
    if(candidate.size() >= 4) {
        while(!candidate.empty()) {
            board[candidate.front().first][candidate.front().second] = '.';
            candidate.pop();
        }
    }
    return popped;
}

bool puyo(vector<vector<char>> &board) {
    int popped = 0;
    for(int i = 11; i >= 0; i--) {
        for(int j = 0; j < 6; j++) {
            if(board[i][j] != '.') {
                popped += bfs(board, i, j);
            }
        }
    }
    fall(board);
    return popped > 0;
}

int main() {
    vector<vector<char>> board(12, vector<char>(6, 0));
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 6; j++) {
            board[i][j] = getchar();
        }
        getchar();
    }
    
    int count = 0;
    while(puyo(board)) {
        count++;
    }
    printf("%d", count);

    return 0;
}