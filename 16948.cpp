#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, r1, c1, r2, c2;
int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};
int depth[200][200];

bool isInBoard(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int bfs() {
    queue<pair<int, int>> q;
    q.push({r1, c1});
    depth[r1][c1] = 0;
    while (!q.empty()) {
        int hereX = q.front().first;
        int hereY = q.front().second;
        q.pop();
        for (int i = 0; i < 6; i++) {
            int nX = hereX + dx[i];
            int nY = hereY + dy[i];
            if (nX == r2 && nY == c2) {
                return depth[hereX][hereY] + 1;
            }
            if (isInBoard(nX, nY) && depth[nX][nY] < 0) {
                depth[nX][nY] = depth[hereX][hereY] + 1;
                q.push({nX, nY});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(depth, -1, sizeof(depth));
    cin >> N >> r1 >> c1 >> r2 >> c2;
    cout << bfs();
    return 0;
}