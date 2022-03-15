#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int partialMin(vector<vector<int>> &minTable, int a, int b) {
    int x = log2(b - a + 1);
    return min(minTable[x][a], minTable[x][b - (1 << x) + 1]);
}

int partialMax(vector<vector<int>> &maxTable, int a, int b) {
    int x = log2(b - a + 1);
    return max(maxTable[x][a], maxTable[x][b - (1 << x) + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    int maxLog = static_cast<int>(log2(N));
    vector<int> arr(N);
    vector<vector<int>> minTable(maxLog + 1, vector<int>(N));
    vector<vector<int>> maxTable(maxLog + 1, vector<int>(N));
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        minTable[0][i] = arr[i];
        maxTable[0][i] = arr[i];
    }
    for (int k = 1; k <= maxLog; k++) {
        for (int i = 0; i + (1 << (k - 1)) < N; i++) {
            minTable[k][i] = min(minTable[k - 1][i], minTable[k - 1][i + (1 << (k - 1))]);
            maxTable[k][i] = max(maxTable[k - 1][i], maxTable[k - 1][i + (1 << (k - 1))]);
        }
    }
    while (M-- > 0) {
        int i, j;
        cin >> i >> j;
        cout << partialMin(minTable, i - 1, j - 1) << ' ' << partialMax(maxTable, i - 1, j - 1) << '\n';
    }
    return 0;
}