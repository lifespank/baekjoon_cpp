#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void nextPtr(list<int>::iterator& it, list<int>& ll) {
    it++;
    if (it == ll.end()) {
        it = ll.begin();
    }
}

void josephus(list<int>& ll, int K) {
    auto it = ll.begin();
    vector<int> v;
    while(!ll.empty()) {
        for(int i = 0; i < K - 1; i++) {
            nextPtr(it, ll);
        }
        v.push_back(*it);
        it = ll.erase(it);
        if (it == ll.end()) {
            it = ll.begin();
        }
    }
    cout << '<';
    for(int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) {
            cout << ", ";
        }
    }
    cout << '>';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    list<int> ll;
    for(int i = 1; i <= N; i++) {
        ll.push_back(i);
    }
    josephus(ll, K);

    return 0;
}