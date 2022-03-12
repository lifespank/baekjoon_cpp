#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>

using namespace std;

int L, C;



void comb(string& alphList, string selected, int idx, int vCount, int cCount) {
    if(selected.size() == L && vCount >= 1 && cCount >= 2) {  // selected의 size가 L인 경우(다 고름)
        cout << selected << "\n";
        return;
    }
    if(idx >= C) {   //index가 전체 알파벳 개수를 넘길 때(다 못 고르는 경우)
        return;
    }
    selected.push_back(alphList[idx]);
    if(alphList[idx] == 'a' || alphList[idx] == 'e' || alphList[idx] == 'i' || alphList[idx] == 'o' || alphList[idx] == 'u') {
        comb(alphList, selected, idx + 1, vCount + 1, cCount);
    }
    else {
        comb(alphList, selected, idx + 1, vCount, cCount + 1);
    }
    selected.pop_back();
    comb(alphList, selected, idx + 1, vCount, cCount);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> L >> C;
    string alphList = "";
    string selected = "";
    for(int i = 0; i < C; i++) {
        char c;
        cin >> c;
        alphList.push_back(c);
    }
    sort(alphList.begin(), alphList.end());
    comb(alphList, selected, 0, 0, 0);
    return 0;
}