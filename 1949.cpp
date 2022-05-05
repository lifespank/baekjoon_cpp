#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int traverse(vector<vector<int>>& realTree, vector<int>& population, vector<vector<int>>& dp, int curr, bool isSuper) {
    if (dp[curr][isSuper] != -1) {
        return dp[curr][isSuper];
    }
    if (isSuper) {
        int childScore = 0;
        for (auto& child: realTree[curr]) {
            childScore += traverse(realTree, population, dp, child, false);
        }
        dp[curr][isSuper] = childScore + population[curr];
    } else {
        int childScore = 0;
        for (auto& child: realTree[curr]) {
            childScore += max(traverse(realTree, population, dp, child, true), traverse(realTree, population, dp, child, false));
        }
        dp[curr][isSuper] = childScore;
    }
    return dp[curr][isSuper];
}

void dfs(vector<vector<int>>& tree, vector<vector<int>>& realTree, vector<bool>& visited, int here) {
    visited[here] = true;
    for (auto& next: tree[here]) {
        if (!visited[next]) {
            realTree[here].push_back(next);
            dfs(tree, realTree, visited, next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> population(N + 1);
    vector<vector<int>> tree(N + 1);
    vector<vector<int>> realTree(N + 1);
    vector<bool> visited(N + 1, false);
    vector<vector<int>> dp(N + 1, vector<int>(2, -1));
    for (int i = 1; i <= N; i++) {
        cin >> population[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int from, to;
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }
    dfs(tree, realTree, visited, 1);
    cout << max(traverse(realTree, population, dp, 1, true), traverse(realTree, population, dp, 1, false));
    return 0;
}