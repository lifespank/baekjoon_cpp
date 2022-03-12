#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N;
double e, w, s, n;
bool visited[29][29];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
double probs[4];

double total;

void dfs(int startX, int startY, int depth, double prob) {
    for(int i = 0; i < 4; i++) {
        int nX = startX + dx[i];
        int nY = startY + dy[i];
        if(!visited[nX][nY] && depth < N) {
            visited[nX][nY] = true;
            dfs(nX, nY, depth + 1, prob * probs[i]);
            visited[nX][nY] = false;
        }
        if(visited[nX][nY] && depth < N) {
            total += prob * probs[i];
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < 4; i++) {
        cin >> probs[i];
        probs[i] /= 100;
    }
    visited[14][14] = true;
    dfs(14, 14, 0, 1);
    cout.precision(11);
    cout << 1 - total;
    return 0;
}