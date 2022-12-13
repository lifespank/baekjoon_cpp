#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#define MAX ((long long)1e9)

using namespace std;

long long s, t;
unordered_map<long long, string> visited;
char ops[3] = {'+', '*', '/'};

long long nextNum(long long num, char opCode) {
    switch (opCode) {
        case '+':
        if (num > MAX - num) {
            return -1;
        }
        num <<= 1;
        break;
        case '*':
        if (num > MAX / num) {
            return -1;
        }
        num *= num;
        break;
        case '/':
        num = 1;
        break;
        default:
        break;
    }
    return num;
}

string bfs() {
    queue<long long> q;
    q.push(s);
    visited[s] = "";
    while (!q.empty()) {
        long long here = q.front();
        string hereStr = visited[here];
        if (here == t) {
            return hereStr;
        }
        q.pop();
        for (int i = 0; i < 3; i++) {
            char opCode = ops[i];
            long long next = nextNum(here, opCode);
            if (next < 1 || next > MAX) {
                continue;
            }
            if (visited.find(next) == visited.end() ||
            visited[next].length() == hereStr.length() + 1 && visited[next].compare(hereStr + opCode) > 0) {
                visited[next] = hereStr + opCode;
                q.push(next);
            }
        }
    }
    return "";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s >> t;
    if (s == t) {
        cout << 0;
    } else if (!t) {
        cout << 1;
    } else {
        string ans = bfs();
        if (!ans.length()) {
            cout << -1;
        } else {
            cout << ans;
        }
    }
    return 0;
}