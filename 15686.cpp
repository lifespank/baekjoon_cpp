#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <cmath>

using namespace std;

int board[50][50];
int N, M;
bool chickenSelected[13];
int minTotal = 1e9;

int distance(pair<int, int> a, pair<int, int> b) {  //a와 b의 맨하탄 거리 계산
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void selectChicken(vector<pair<int, int>>& houseList, vector<pair<int, int>>& chickenList, int idx, int selected) {
    if(chickenList.size() == M) {      //치킨집이 정확히 M개 있는 경우 조합을 계산하지 않고 바로 계산
        int distSum = 0;
        for(auto house : houseList) {
            int minDist =1e9;
            for(int i = 0; i < chickenList.size(); i++) {
                minDist = min(minDist, distance(house, chickenList[i]));
            }
            distSum += minDist;
        }
        minTotal = min(minTotal, distSum);
        return;
    }
    if(selected == M) {              //M개 골랐을 경우
        int distSum = 0;
        for(auto house : houseList) {
            int minDist = 1e9;
            for(int i = 0; i < chickenList.size(); i++) {
                if(chickenSelected[i]) {
                    minDist = min(minDist, distance(house, chickenList[i]));
                }
            }
            distSum += minDist;
        }
        minTotal = min(minTotal, distSum);
        return;
    }
    if(idx >= chickenList.size()) {
        return;
    }
    chickenSelected[idx] = true;
    selectChicken(houseList, chickenList, idx + 1, selected + 1);  //고른 경우
    chickenSelected[idx] = false;
    selectChicken(houseList, chickenList, idx + 1, selected);      //안 고른 경우
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    vector<pair<int, int>> houseList;
    vector<pair<int, int>> chickenList;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) {
                houseList.push_back({i, j});
            }
            else if(board[i][j] == 2) {
                chickenList.push_back({i, j});
            }
        }
    }
    selectChicken(houseList, chickenList, 0, 0);
    cout << minTotal;
    return 0;
}