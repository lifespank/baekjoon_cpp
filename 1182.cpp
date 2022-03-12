#include <iostream>
#include <vector>

using namespace std;

void select(vector<int> &v, vector<int> &selected, int sum, int &count, int target, int curIdx) {
    if (curIdx == v.size()) {
        if (selected.size() > 0 && sum == target) {
            count++;
        }
        return;
    }
    selected.push_back(v[curIdx]);
    select(v, selected, sum + v[curIdx], count, target, curIdx + 1);
    selected.pop_back();
    select(v, selected, sum, count, target, curIdx + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s;
    cin >> n >> s;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> selected;
    int count = 0;
    select(v, selected, 0, count, s, 0);
    cout << count;
    return 0;
}