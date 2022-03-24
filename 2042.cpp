#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long initTree(vector<long long> &arr, vector<long long> &tree, int node, int low, int high) {
    if (low == high) {
        return tree[node] = arr[low];
    }
    int mid = low + (high - low) / 2;
    return tree[node] = initTree(arr, tree, node * 2, low, mid) + initTree(arr, tree, node * 2 + 1, mid + 1, high);
}

void updateTree(vector<long long> &tree, int node, int idx, int low, int high, long long diff) {
    if (idx < low || idx > high) {
        return;
    }
    tree[node] += diff;
    if (low != high) {
        int mid = low + (high - low) / 2;
        updateTree(tree, node * 2, idx, low, mid, diff);
        updateTree(tree, node * 2 + 1, idx, mid + 1, high, diff);
    }
}

long long sum(vector<long long> &tree, int node, int low, int high, int left, int right) {
    if (left > high || right < low) {
        return 0;
    }
    if (left <= low && right >= high) {
        return tree[node];
    }
    int mid = low + (high - low) / 2;
    return sum(tree, node * 2, low, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, high, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> arr(N);
    int h = static_cast<int>(ceil(log2(N)));
    int treeSize = (1 << (h + 1));
    vector<long long> tree(treeSize);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    initTree(arr, tree, 1, 0, N - 1);
    for (int i = 0; i < M + K; i++) {
        int op;
        long long left, right;
        cin >> op >> left >> right;
        if (op == 1) {
            updateTree(tree, 1, left - 1, 0, N - 1, right - arr[left - 1]);
            arr[left - 1] = right;
        } else {
            cout << sum(tree, 1, 0, N - 1, left - 1, right - 1) << '\n';
        }
    }
    return 0;
}