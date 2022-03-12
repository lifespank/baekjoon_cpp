#include <iostream>
#include <queue>
#include <bits/stdc++.h>
#include <string>

using namespace std;
int N;

struct compare {
    bool operator() (pair<int, string>& a, pair<int, string>& b) {
        if (a.first != b.first) {
            return a.first < b.first;
        } else {
            return a.second > b.second; 
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;
    cin >> N;
    for(int i = 0; i < N; i++) {
        string name;
        int score;
        cin >> name >> score;
        pq.push({score, name});
    }
    cout << pq.top().second;
    
    return 0;
}