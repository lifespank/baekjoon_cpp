#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>

using namespace std;

vector<int> friends[50];
bool visited[50];
int insa;
int maxfriend;
int count2friend;

void bfs(int start) {
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;
    while(!q.empty()) {
        int here = q.front().first;
        int dth = q.front().second;
        q.pop();
        for(auto fr : friends[here]) {
            if(!visited[fr] && dth < 2) {
                visited[fr] = true;
                count2friend++;
                maxfriend = max(maxfriend, count2friend);
                q.push({fr, dth + 1});
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            char c = getchar();
            if(c == 'Y') {
                friends[i].push_back(j);
            }
        }
        getchar();
    }
    for(int i = 0; i < N; i++) {
        memset(visited, 0, sizeof(visited));
        count2friend = 0;
        bfs(i);
    }
    printf("%d", maxfriend);
    return 0;
}