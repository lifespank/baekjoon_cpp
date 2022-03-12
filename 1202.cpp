#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> jewels(n);
    vector<int> bags(k);
    for (int i = 0; i < n; i++) {
        int mass, value;
        cin >> mass >> value;
        jewels[i] = {mass, value};
    }
    for (int i = 0; i < k; i++) {
        cin >> bags[i];
    }
    sort(jewels.begin(), jewels.end());
    sort(bags.begin(), bags.end());
    int jewelIdx = 0;
    long long ans = 0;
    priority_queue<int> pq;
    for (int i = 0; i < k; i++) {
        while (jewelIdx < n && jewels[jewelIdx].first <= bags[i]) {
            pq.push(jewels[jewelIdx++].second);
        }
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
    return 0;
}