#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<pair<int, int>> &tree, vector<pair<int, int>> &depthCols, int here, int dth, int &colNum) {
    int left = tree[here].first;
    int right = tree[here].second;
    if (left != -1) {
        dfs(tree, depthCols, left, dth + 1, colNum);
    }
    if (!depthCols[dth].first && !depthCols[dth].second) {
        depthCols[dth].first = colNum++;
    } else {
        depthCols[dth].second = colNum++;
    }
    if (right != -1) {
        dfs(tree, depthCols, right, dth + 1, colNum);
    }
}

int findRoot(vector<int> &parent, int here) {
    if (!parent[here]) {
        return here;
    }
    return findRoot(parent, parent[here]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<pair<int, int>> tree(N + 1, {-1, -1});
    vector<pair<int, int>> depthCols(N + 1, {0, 0});
    vector<int> parent(N + 1, 0);
    for (int i = 0; i < N; i++) {
        int mom, left, right;
        cin >> mom >> left >> right;
        tree[mom] = {left, right};
        parent[left] = mom;
        parent[right] = mom;
    }
    int colNum = 1;
    int root = findRoot(parent, 4);
    dfs(tree, depthCols, root, 1, colNum);
    int maxIdx = 0;
    int maxVal = 0;
    for (int i = 1; i < depthCols.size(); i++) {
        if (depthCols[i].first && depthCols[i].second) {
            if (maxVal < depthCols[i].second - depthCols[i].first + 1) {
                maxVal = depthCols[i].second - depthCols[i].first + 1;
                maxIdx = i;
            }
        } else if (depthCols[i].first) {
            if (maxVal < 1) {
                maxVal = 1;
                maxIdx = i;
            }
        }
    }
    cout << maxIdx << ' ' << maxVal;
    return 0;
}