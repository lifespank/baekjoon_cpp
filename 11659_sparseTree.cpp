#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int partialMin(vector<vector<int>> &table, int a, int b) {
    int diff = b - a + 1;
    int sum = 0;
    for (int i = table.size() - 1, j = a; i >= 0; i--) {
        if (diff & (1 << i)) {
            sum += table[i][j];
            j += (1 << i);
        }
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    int maxLog = static_cast<int>(log2(N));
    vector<int> arr(N);
    vector<vector<int>> table(maxLog + 1, vector<int>(N));
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        table[0][i] = arr[i];
    }
    for (int k = 1; k <= maxLog; k++) {
        for (int i = 0; i < N; i++) {
            table[k][i] = table[k - 1][i] + table[k - 1][i + (1 << (k - 1))];
        }
    }
    while (M-- > 0) {
        int i, j;
        cin >> i >> j;
        cout << partialMin(table, i - 1, j - 1) << '\n';
    }
    return 0;
}