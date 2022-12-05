#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int T, A, B;
char ops[4] = {'D', 'S', 'L', 'R'};
char ansOpr[10000];
int rightBefore[10000];
int depth[10000];

int opr(char code, int n) {
    int ret;
    int d[4];
    int num = n;
    for (int i = 0; i < 4; i++) {
        d[i] = num % 10;
        num /= 10;
    }
    switch (code) {
        case 'D':
        ret = 2 * n % 10000;
        break;
        case 'S':
        ret = n - 1;
        if (ret < 0) {
            ret = 9999;
        }
        break;
        case 'L':
        ret = d[2] * 1000 + d[1] * 100 + d[0] * 10 + d[3];
        break;
        case 'R':
        ret = d[0] * 1000 + d[3] * 100 + d[2] * 10 + d[1];
        break;
        default:
        ret = -1;
        break;
    }
    return ret;
}

void bfs() {
    queue<int> q;
    q.push(A);
    depth[A] = 0;
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int next = opr(ops[i], here);
            if (depth[next] < 0) {
                depth[next] = depth[here] + 1;
                rightBefore[next] = here;
                ansOpr[next] = ops[i];
                if (next == B) {
                    return;
                }
                q.push(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T-- > 0) {
        cin >> A >> B;
        memset(rightBefore, -1, sizeof(rightBefore));
        memset(depth, -1, sizeof(depth));
        bfs();
        vector<char> ans;
        while (rightBefore[B] >= 0) {
            ans.push_back(ansOpr[B]);
            B = rightBefore[B];
        }
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}