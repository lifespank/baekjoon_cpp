#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int N;
int board[20][20];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool isInBoard(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

class Seat {
    public:
    int x;
    int y;
    vector<int> likes;

    Seat(int x, int y, vector<int>& likes) {
        this->x = x;
        this->y = y;
        this->likes = likes;
    }

    int nearBlank() {
        int count = 0;
        for(int i = 0; i < 4; i++) {
            int nX = x + dx[i];
            int nY = y + dy[i];
            if (isInBoard(nX, nY) && !board[nX][nY]) {
                count++;
            }
        }
        return count;
    }

    int nearScore() {
        int count = 0;
        for(int i = 0; i < 4; i++) {
            int nX = x + dx[i];
            int nY = y + dy[i];
            if (isInBoard(nX, nY) && find(likes.begin(), likes.end(), board[nX][nY]) != likes.end()) {
                count++;
            }
        }
        int score;
        switch(count) {
            case 0:
            score = 0;
            break;
            case 1:
            score = 1;
            break;
            case 2:
            score = 10;
            break;
            case 3:
            score = 100;
            break;
            case 4:
            score = 1000;
            break;
            default:
            break;
        }
        return score;
    }
};

struct compare {
    bool operator()(struct Seat& a, struct Seat& b) {
        int bNearScore = b.nearScore();
        int aNearScore = a.nearScore();
        int bNearBlank = b.nearBlank();
        int aNearBlank = a.nearBlank();
        if (bNearScore > aNearScore) {
            return true;
        } else if (bNearScore < aNearScore) {
            return false;
        } else {
            if (bNearBlank > aNearBlank) {
                return true;
            } else if (bNearBlank < aNearBlank) {
                return false;
            } else {
                if (b.x < a.x) {
                    return true;
                } else if (b.x > a.x) {
                    return false;
                } else {
                    return b.y < a.y;
                }
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    vector<Seat> students;

    for(int student = 0; student < N * N; student++) {
        priority_queue<Seat, vector<Seat>, compare> pq;
        int num;
        vector<int> likes;
        cin >> num;
        for(int k = 0; k < 4; k++) {
            int temp;
            cin >> temp;
            likes.push_back(temp);
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if (!board[i][j]) {
                    pq.push(Seat(i, j, likes));
                }
            }
        }
        Seat seat = pq.top();
        board[seat.x][seat.y] = num;
        students.push_back(seat);

    }

    int score = 0;
    for(int i = 0; i < students.size(); i++) {
        score += students[i].nearScore();
    }
    cout << score;
    
    return 0;
}