#include <iostream>
#include <cstring>
#include <queue>
#include <unordered_map>

using namespace std;

int N, K;
unordered_map<int, int> visit;

int bfs() {
    queue<int> q;
    visit.insert({N, 0});
    q.push(N);
    while(!q.empty()) {
        int tmp = q.front();
        int depth = visit.at(tmp);
        if(tmp == K) {
            return depth;
        }
        q.pop();
        int possibleMove[3] = {tmp - 1, tmp + 1, tmp * 2};
        for(int i = 0; i < 3; i++) {
            if(possibleMove[i] >= 0 && possibleMove[i] <= 100000 && visit.find(possibleMove[i]) == visit.end()) {
                q.push(possibleMove[i]);
                visit.insert({possibleMove[i], depth + 1});
            }
        }
    }
    return -1;
}


int main() {
    cin >> N >> K;
    cout << bfs();
    return 0;
}