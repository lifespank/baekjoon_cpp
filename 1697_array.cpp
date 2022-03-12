#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, K;
int visit[100001];

int bfs() {
    queue<int> q;
    visit[N] = 0;
    q.push(N);
    while(!q.empty()) {
        int tmp = q.front();
        int depth = visit[tmp];
        if(tmp == K) {
            return depth;
        }
        q.pop();
        int possibleMove[3] = {tmp - 1, tmp + 1, tmp * 2};
        for(int i = 0; i < 3; i++) {
            if(possibleMove[i] >= 0 && possibleMove[i] <= 100000 && visit[possibleMove[i]] == -1) {
                q.push(possibleMove[i]);
                visit[possibleMove[i]] = depth + 1;
            }
        }
    } 
    return -1;
}


int main() {
    memset(visit, -1, sizeof(visit));
    cin >> N >> K;
    cout << bfs();
    return 0;
}