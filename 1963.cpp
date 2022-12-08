#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int T, start, target;
bool isPrime[10000];
int depth[10000];

void getPrimes() {
    memset(isPrime, -1, sizeof(isPrime));
    for (int i = 2; i * i <= 9999; i++) {
        if (isPrime[i]) {
            for (int j = 1000 / i * i; j <= 9999; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int toOneNum(int d[]) {
    return d[0] + 10 * d[1] + 100 * d[2] + 1000 * d[3];
}

void pushToQ(int num, queue<int>& q) {
    int d[4];
    int tempNum = num;
    for (int i = 0; i < 4; i++) {
        d[i] = tempNum % 10;
        tempNum /= 10;
    }
    for (int i = 0; i < 4; i++) {
        int temp = d[i];
        for (d[i]= 0; d[i] < 10; d[i]++) {
            if (d[i] != temp) {
                int newNum = toOneNum(d);
                if (isPrime[newNum] && depth[newNum] < 0 && newNum >= 1000) {
                    q.push(newNum);
                    depth[newNum] = depth[num] + 1;
                }
            }
        }
        d[i] = temp;
    }
}

int bfs() {
    queue<int> q;
    q.push(start);
    memset(depth, -1, sizeof(depth));
    depth[start] = 0;
    while (!q.empty()) {
        int here = q.front();
        if (here == target) {
            return depth[here];
        }
        q.pop();
        pushToQ(here, q);
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    getPrimes();
    cin >> T;
    while (T-- > 0) {
        cin >> start >> target;
        int ans = bfs();
        if (ans < 0) {
            cout << "Impossible\n";
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}