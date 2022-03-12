#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <unordered_map>

using namespace std;

pair<int, int> stringToTime(string str) {
    int hour = stoi(str.substr(0, 2));
    int minute = stoi(str.substr(3, 2));
    return {hour, minute};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<string, pair<int, int>> check; 
    string startStr, endStr, endStreamStr;
    pair<int, int> start, end, endStream;
    cin >> startStr >> endStr >> endStreamStr;
    start = stringToTime(startStr);
    end = stringToTime(endStr);
    endStream = stringToTime(endStreamStr);
    while(true) {
        string timeString, name;
        cin >> timeString >> name;
        if (cin.eof()) {
            break;
        }
        pair<int, int> time = stringToTime(timeString);
        if (time <= start) {
            check[name].first++;
        }
        if (time >= end && time <= endStream) {
            check[name].second++;
        }
    }
    int count = 0;
    for(auto it = check.begin(); it != check.end(); it++) {
        if((*it).second.first > 0 && (*it).second.second > 0) {
            count++;
        }
    }
    cout << count;
    return 0;
}