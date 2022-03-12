#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int dpMax[2][3];
    int dpMin[2][3];
    cin >> dpMax[0][0] >> dpMax[0][1] >> dpMax[0][2];
    copy(dpMax[0], dpMax[0] + 3, dpMin[0]);
    if (n > 1) {
        for (int ptr = 1; ptr < n; ptr++) {
            cin >> dpMax[1][0] >> dpMax[1][1] >> dpMax[1][2];
            copy(dpMax[1], dpMax[1] + 3, dpMin[1]);
            dpMax[1][0] += max(dpMax[0][0], dpMax[0][1]);
            dpMax[1][1] += max({dpMax[0][0], dpMax[0][1], dpMax[0][2]});
            dpMax[1][2] += max(dpMax[0][1], dpMax[0][2]);
            dpMin[1][0] += min(dpMin[0][0], dpMin[0][1]);
            dpMin[1][1] += min({dpMin[0][0], dpMin[0][1], dpMin[0][2]});
            dpMin[1][2] += min(dpMin[0][1], dpMin[0][2]);
            copy(dpMax[1], dpMax[1] + 3, dpMax[0]);
            copy(dpMin[1], dpMin[1] + 3, dpMin[0]);
        }
        cout << *max_element(dpMax[1], dpMax[1] + 3) << ' ' << *min_element(dpMin[1], dpMin[1] + 3);
    } else {
        cout << *max_element(dpMax[0], dpMax[0] + 3) << ' ' << *min_element(dpMin[0], dpMin[0] + 3);
    }
    return 0;
}