#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>

using namespace std;
int buildings[51];

double inclination(pair<int, int> a, pair<int, int> b) {
    return (b.second - a.second) / (double)(b.first - a.first);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> buildings[i];
    }
    int maxCount = -1;
    for(int i = 1; i <= N; i++) {
        int count = 0;
        //left
        double incl = 1e9;
        for(int j = i - 1; j >= 1; j--) {
            double tempIncl = inclination({j, buildings[j]}, {i, buildings[i]});
            if (incl > tempIncl) {
                count++;
                incl = tempIncl;
            }
        }
        //right
        incl = -1e9;
        for(int j = i + 1; j <= N; j++) {
            double tempIncl = inclination({i, buildings[i]}, {j, buildings[j]});
            if (incl < tempIncl) {
                count++;
                incl = tempIncl;
            }
        }
        maxCount = max(maxCount, count);
    }
    cout << maxCount;
    return 0;
}