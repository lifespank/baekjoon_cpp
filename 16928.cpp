#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, M;
int whereTo[101];
int depth[101];

int bfs() {
    queue<int> q;
    q.push(1);
    depth[1] = 0;
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++) {
            int next = here + i;
            if (next <= 100) {
                if (whereTo[next]) {
                    next = whereTo[next];
                }
                if (depth[next] < 0) {
                    if (next == 100) {
                        return depth[here] + 1;
                    }
                    depth[next] = depth[here] + 1;
                    q.push(next);
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    memset(depth, -1, sizeof(depth));
    for (int i = 0; i < N + M; i++) {
        int from, to;
        cin >> from >> to;
        whereTo[from] = to;
    }
    for (int i = 2; i < 100; i++) {
        int next = whereTo[i];
        while (next) {
            whereTo[i] = next;
            next = whereTo[next];
        }
    }
    cout << bfs();
    return 0;
}