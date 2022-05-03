#include <iostream>
#include <algorithm>

using namespace std;

int numPressCount(int n, bool broken[]) {
    if (n == 0) {
        if (broken[0]) {
            return 0;
        }
        return 1;
    }
    int count = 0;
    while (n > 0) {
        if (broken[n % 10]) {
            return 0;
        }
        n /= 10;
        count++;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    bool broken[10] = { false };
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        broken[temp] = true;
    }
    int minCount = abs(n - 100);
    for (int i = 0; i <= 1000000; i++) {
        int numPress = numPressCount(i, broken);
        if (numPress > 0) {
            minCount = min(minCount, numPress + abs(n - i));
        }
    }
    cout << minCount;
    return 0;
}