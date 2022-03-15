#include <iostream>
#include <vector>
#define MAX_LOG_K 20

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m, Q, n, x;
    cin >> m;
    vector<int> f(m + 1);
    vector<vector<int>> table(MAX_LOG_K + 1, vector<int>(m + 1));
    for (int i = 1; i <= m; i++) {
        cin >> f[i];
    }
    for (int i = 1; i <= m; i++) {
        table[0][i] = f[i];
    }
    for (int k = 1; k <= MAX_LOG_K; k++) {
        for (int i = 1; i <= m; i++) {
            table[k][i] = table[k - 1][table[k - 1][i]];
        }
    }
    cin >> Q;
    while (Q-- > 0) {
        cin >> n >> x;
        for (int i = MAX_LOG_K; i >= 0; i--) {
            if (n & (1 << i)) {
                x = table[i][x];
            }
        }
        cout << x << '\n';
    }
    return 0;
}