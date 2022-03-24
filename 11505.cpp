#include <iostream>
#include <vector>
#include <cmath>
#define PRIME 1000000007

using namespace std;

long long initTree(vector<long long> &arr, vector<long long> &tree, int start, int end, int node) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    int mid = start + (end - start) / 2;
    return tree[node] = (initTree(arr, tree, start, mid, node * 2) * initTree(arr, tree, mid + 1, end, node * 2 + 1)) % PRIME;
}

long long updateTree(vector<long long> &tree, int start, int end, int idx, int node, long long val) {
    if (idx < start || idx > end) {
        return tree[node];
    }
    if (start != end) {
        int mid = start + (end - start) / 2;
        return tree[node] = (updateTree(tree, start, mid, idx, node * 2, val) * updateTree(tree, mid + 1, end, idx, node * 2 + 1, val)) % PRIME;
    }
    return tree[node] = val;
}

long long product(vector<long long> &tree, int start, int end, int left, int right, int node) {
    if (left > end || right < start) {
        return 1;
    }
    if (left <= start && right >= end) {
        return tree[node];
    }
    int mid = start + (end - start) / 2;
    return (product(tree, start, mid, left, right, node * 2) * product(tree, mid + 1, end, left, right, node * 2 + 1)) % PRIME;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> arr(N);
    int h = ceil(log2(N));
    int treeSize = 1 << (h + 1);
    vector<long long> tree(treeSize);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    initTree(arr, tree, 0, N - 1, 1);
    for (int i = 0; i < M + K; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if (a == 1) {
            updateTree(tree, 0, N - 1, b - 1, 1, c);
            arr[b - 1] = c;
        } else {
            cout << product(tree, 0, N - 1, b - 1, c - 1, 1) << '\n';
        }
    }
    return 0;
}