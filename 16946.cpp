#include <cstdio>
#include <queue>
#include <unordered_set>

using namespace std;

int N, M;
int board[1000][1000];
int numBoard[1000][1000];
int areaCount[500000];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isInBoard(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

void bfs(int x, int y, int num) {
    queue<pair<int, int>> q;
    q.push({x, y});
    numBoard[x][y] = num;
    int count = 0;
    while (!q.empty()) {
        int hereX = q.front().first;
        int hereY = q.front().second;
        count++;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nX = hereX + dx[i];
            int nY = hereY + dy[i];
            if (isInBoard(nX, nY) && !numBoard[nX][nY] && !board[nX][nY]) {
                numBoard[nX][nY] = num;
                q.push({nX, nY});
            }
        }
    }
    areaCount[num] = count;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &board[i][j]);
        }
    }
    int num = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!board[i][j] && !numBoard[i][j]) {
                num++;
                bfs(i, j, num);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j]) {
                int count = 1;
                unordered_set<int> s;
                for (int dir = 0; dir < 4; dir++) {
                    int nX = i + dx[dir];
                    int nY = j + dy[dir];
                    if (isInBoard(nX, nY) && s.find(numBoard[nX][nY]) == s.end()) {
                        s.insert(numBoard[nX][nY]);
                        count += areaCount[numBoard[nX][nY]];
                        count %= 10;
                    }
                }
                count %= 10;
                board[i][j] = count;
            }
            printf("%d", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}