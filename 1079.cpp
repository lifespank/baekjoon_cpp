#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int maxRound = 0;

void playGame(priority_queue<pair<int, int>>& players, vector<vector<int>>& response, int eunjin, int round) {
    if (players.size() & 1) { //낮
        priority_queue<pair<int, int>> nextPlayers;
        if (-players.top().second == eunjin) {
            maxRound = max(maxRound, round);
            return;
        }
        players.pop();
        while (!players.empty()) {
            pair<int, int> player = players.top();
            players.pop();
            nextPlayers.push(player);
        }
        playGame(nextPlayers, response, eunjin, round);
    } else { //밤
        if (players.size() == 1) {
            maxRound = max(maxRound, round);
            return;
        }
        vector<pair<int, int>> survivors;
        while (!players.empty()) {
            survivors.push_back(players.top());
            players.pop();
        }
        for (int dead = 0; dead < survivors.size(); dead++) {
            if (-survivors[dead].second != eunjin) {
                priority_queue<pair<int, int>> nextPlayers;
                for (int i = 0; i < survivors.size(); i++) {
                    if (i != dead) {
                        nextPlayers.push({survivors[i].first + response[-survivors[dead].second][-survivors[i].second], survivors[i].second});
                    }
                }
                playGame(nextPlayers, response, eunjin, round + 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<vector<int>> response(N, vector<int>(N));
    priority_queue<pair<int, int>> players;   //유죄지수, 번호
    int eunjin;
    for (int i = 0; i < N; i++) {
        int guilt;
        cin >> guilt;
        players.push({guilt, -i});
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> response[i][j];
        }
    }
    cin >> eunjin;
    playGame(players, response, eunjin, 0);
    cout << maxRound;
    return 0;
}