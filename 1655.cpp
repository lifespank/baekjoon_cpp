#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (maxHeap.size() == 0) {
            maxHeap.push(temp);
        } else if (minHeap.size() < maxHeap.size()) {
            minHeap.push(temp);
        } else {
            maxHeap.push(temp);
        }
        if (!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()) {
            int minTop = minHeap.top();
            int maxTop = maxHeap.top();
            minHeap.pop();
            maxHeap.pop();
            minHeap.push(maxTop);
            maxHeap.push(minTop);
        }
        cout << maxHeap.top() << '\n';
    }
    return 0;
}