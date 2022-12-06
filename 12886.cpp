#include <iostream>
#include <queue>

using namespace std;

int A, B, C, N;
bool visited[1500][1500];

pair<int, int> getNext(int x, int y) {
    if (x < y) {
        y -= x;
        x <<= 1;
    } else {
        x -= y;
        y <<= 1;
    }
    return {x, y};
}

void pushQ(queue<pair<int, int>>& q, int nextA, int nextB) {
    if (!visited[nextA][nextB]) {
        q.push({nextA, nextB});
        visited[nextA][nextB] = true;
    }
}

bool bfs() {
    queue<pair<int, int>> q;
    q.push({A, B});
    visited[A][B] = true;
    while (!q.empty()) {
        int hereA = q.front().first;
        int hereB = q.front().second;
        int hereC = N - hereA - hereB;
        if (hereA == hereB && hereB == hereC) {
            return true;
        }
        int nextA, nextB, nextC;
        q.pop();
        nextC = hereC;
        if (hereA != hereB) {
            pair<int, int> nextPair = getNext(hereA, hereB);
            nextA = nextPair.first;
            nextB = nextPair.second;
            pushQ(q, nextA, nextB);
        }
        nextA = hereA;
        if (hereB != hereC) {
            pair<int ,int> nextPair = getNext(hereB, hereC);
            nextB = nextPair.first;
            pushQ(q, nextA, nextB);
        }
        nextB = hereB;
        if (hereA != hereC) {
            pair<int, int> nextPair = getNext(hereA, hereC);
            nextA = nextPair.first;
            pushQ(q, nextA, nextB);
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> A >> B >> C;
    N = A + B + C;
    if (N % 3) {
        cout << 0;
    } else {
        cout << bfs();
    }
    return 0;
}