#include <iostream>
#include <vector>

using namespace std;


void solve(vector<int> &postOrder, vector<int> &inOrder, vector<int> &inIdx, int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) {
        return;
    }
    int root = postOrder[postEnd];
    cout << root << ' ';
    solve(postOrder, inOrder, inIdx, inStart, inIdx[root] - 1, postStart, postStart + inIdx[root] - inStart - 1);
    solve(postOrder, inOrder, inIdx, inIdx[root] + 1, inEnd, postStart + inIdx[root] - inStart, postEnd - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> inOrder(n);
    vector<int> postOrder(n);
    vector<int> inIdx(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> inOrder[i];
        inIdx[inOrder[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> postOrder[i];
    }
    solve(postOrder, inOrder, inIdx, 0, n - 1, 0, n - 1);
    return 0;
}