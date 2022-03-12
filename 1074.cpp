#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void traverse(int x, int y, int targetX, int targetY, int &depth, int size) {
    if (x == targetX && y == targetY) {
        cout << depth;
        return;
    }
    if (x <= targetX && targetX < x + size && y <= targetY && targetY < y + size) {
        traverse(x, y, targetX, targetY, depth, size / 2);
        traverse(x, y + size / 2, targetX, targetY, depth, size / 2);
        traverse(x + size / 2, y, targetX, targetY, depth, size / 2);
        traverse(x + size / 2, y + size / 2, targetX, targetY, depth, size / 2);
    } else {
        depth += size * size;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, r, c;
    cin >> n >> r >> c;
    int size = 1 << n;
    int depth = 0;
    traverse(0, 0, r, c, depth, size);
    return 0;
}