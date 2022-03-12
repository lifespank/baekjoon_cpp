#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int alphas[26] = { 0 };
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = temp.size() - 1, place = 1; j >= 0; j--, place *= 10) {
            alphas[temp[j] - 'A'] += place;
        }
    }
    sort(alphas, alphas + 26, greater<>());
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += alphas[i] * (9 - i);
    }
    cout << ans;
    return 0;
}