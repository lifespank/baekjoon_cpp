#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int S[21][21];
int minDiff = 1e9;

void comb(vector<bool> isStartTeam, int selected, int idx) {
    if(!minDiff) {
        return;
    }
    if(selected == N / 2) {
        int startTeamSum = 0;
        int linkTeamSum = 0;
        vector<int> startTeam;
        vector<int> linkTeam;
        for(int i = 1; i <= N; i++) {
            if(isStartTeam[i]) {
                startTeam.push_back(i);
            }
            else {
                linkTeam.push_back(i);
            }
        }
        for(int i = 0; i < N / 2 - 1; i++) {
            for(int j = i + 1; j < N / 2; j++) {
                startTeamSum += S[startTeam[i]][startTeam[j]] + S[startTeam[j]][startTeam[i]];
                linkTeamSum += S[linkTeam[i]][linkTeam[j]] + S[linkTeam[j]][linkTeam[i]];
            }
        }
        minDiff = min(minDiff, abs(startTeamSum - linkTeamSum));
        return;
    }
    if(idx > N) {
        return;
    }
    isStartTeam[idx] = true;
    comb(isStartTeam, selected + 1, idx + 1);
    isStartTeam[idx] = false;
    comb(isStartTeam, selected, idx + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> S[i][j];
        }
    }
    vector<bool> isStartTeam(21, 0);
    comb(isStartTeam, 0, 1);

    cout << minDiff;

    return 0;
}