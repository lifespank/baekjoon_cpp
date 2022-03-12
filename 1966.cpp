#include <iostream>
#include <deque>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

bool isMax(deque<pair<int, int>>& deq, int n) {
    for(auto it = deq.begin(); it != deq.end(); it++) {
        if (it->first > n) {
            return false;
        }
    }
    return true;
}

int printCalc(deque<pair<int, int>>& deq, int& M) {
    int count = 0;
    while (!deq.empty()) {
        int outPriority = deq.front().first;
        int outIndex = deq.front().second;
        deq.pop_front();
        if (!isMax(deq, outPriority)) {
            deq.push_back({outPriority, outIndex});
        } else {
            count++;
            if (outIndex == M) {
                return count;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testCase;
    cin >> testCase;
    for(int tc = 0; tc < testCase; tc++) {
        int N, M;
        cin >> N >> M;
        deque<pair<int, int>> deq;
        for(int i = 0; i < N; i++) {
            int temp;
            cin >> temp;
            deq.push_back({temp, i});
        }
        cout << printCalc(deq, M) << '\n';
    }

    return 0;
}