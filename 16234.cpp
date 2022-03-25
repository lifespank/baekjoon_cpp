#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isInRange(int thisPeople, int otherPeople, int L, int R) {
    int diff = abs(thisPeople - otherPeople);
    return L <= diff && diff <= R;
}

bool isInBoard(int x, int y, int N) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool bfs(vector<vector<int>> &board, vector<vector<bool>> &visited, int startX, int startY, int L, int R) {
    queue<pair<int, int>> q;
    queue<pair<int, int>> allies;
    int totalPeople = board[startX][startY];
    int allyCount = 1;
    visited[startX][startY] = true;
    q.push({startX, startY});
    allies.push({startX, startY});
    while (!q.empty()) {
        int hereX = q.front().first;
        int hereY = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nX = hereX + dx[i];
            int nY = hereY + dy[i];
            if (isInBoard(nX, nY, board.size()) && !visited[nX][nY] && isInRange(board[hereX][hereY], board[nX][nY], L, R)) {
                q.push({nX, nY});
                allies.push({nX, nY});
                visited[nX][nY] = true;
                allyCount++;
                totalPeople += board[nX][nY];
            }
        }
    }
    if (allyCount == 1) {
        return false;
    }
    int resultPeople = totalPeople / allyCount;
    while (!allies.empty()) {
        int hereX = allies.front().first;
        int hereY = allies.front().second;
        allies.pop();
        board[hereX][hereY] = resultPeople;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, L, R;
    cin >> N >> L >> R;
    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    int moveCount = -1;
    bool isMoved = true;
    while (isMoved) {
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        isMoved = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && bfs(board, visited, i, j, L, R)) {
                    isMoved = true;
                }
            }
        }
        moveCount++;
    }
    cout << moveCount;
    return 0;
}