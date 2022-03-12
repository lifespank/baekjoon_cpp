#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
char board[25][25];
bool visit[25][25];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<int> villages;

void consumeNewLine() {
    while(getchar() != '\n') {}
}

void bfs(int startX, int startY) {
    if(visit[startX][startY]) {
        return;
    }
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visit[startX][startY] = true;
    int howMany = 0;
    while(!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();
        howMany++;
        for(int i = 0; i < 4; i++) {
            int nX = tmp.first + dx[i];
            int nY = tmp.second + dy[i];
            if(nX >= 0 && nX < N && nY >= 0 && nY < N && !visit[nX][nY] && board[nX][nY] == '1') {
                q.push({nX, nY});
                visit[nX][nY] = true;
            }
        }
    }
    villages.push_back(howMany);
}

int main() {
    cin >> N;
    consumeNewLine();
    memset(visit, 0, sizeof(visit));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            board[i][j] = getchar();
        }
        consumeNewLine();
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] == '1') {
                bfs(i, j);
            }
        }
    }
    cout << villages.size() << '\n';
    sort(villages.begin(), villages.end());
    for(auto it = villages.begin(); it != villages.end(); it++) {
        cout << *it << '\n';
    }

    
    return 0;
}