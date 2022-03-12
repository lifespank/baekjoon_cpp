#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};
int R, C, M;

int reverseDir(int d) {
    int ans;
    switch (d) {
        case 1:
        ans = 2;
        break;
        case 2:
        ans = 1;
        break;
        case 3:
        ans = 4;
        break;
        case 4:
        ans = 3;
        break;
    }
    return ans;
}

bool isInBoard(int x, int y) {
    return x >= 1 && x <= R && y >= 1 && y <= C;
}

class Shark {
    public:
    Shark(int r, int c, int s, int d, int z) {
        this->r = r;
        this->c = c;
        this->s = s;
        this->d = d;
        this->z = z;
    }

    void move() {
        for (int i = 0; i < s; i++) {
            int nR = r + dx[d];
            int nC = c + dy[d];
            if (!isInBoard(nR, nC)) {
                d = reverseDir(d);
                nR = r + dx[d];
                nC = c + dy[d];
            }
            r = nR;
            c = nC;
        }
    }

    int r;
    int c;
    int s;
    int d;
    int z;
};

struct compare {
    bool operator() (const Shark &lhs, const Shark &rhs) const {
        return lhs.z > rhs.z;
    }
};

int findShark(vector<vector<priority_queue<Shark, vector<Shark>, compare>>> &board, int col) {
    for (int i = 1; i < board.size(); i++) {
        if (!board[i][col].empty()) {
            int size = board[i][col].top().z;
            board[i][col].pop();
            return size;
        }
    }
    return 0;
}

void moveShark(vector<vector<priority_queue<Shark, vector<Shark>, compare>>> &board) {
    queue<Shark> movedShark;
    for (int i = 1; i < board.size(); i++) {
        for (int j = 1; j < board[i].size(); j++) {
            if (!board[i][j].empty()) {
                Shark shark = board[i][j].top();
                board[i][j].pop();
                shark.move();
                movedShark.push(shark);
            }
        }
    }
    while (!movedShark.empty()) {
        Shark shark = movedShark.front();
        movedShark.pop();
        board[shark.r][shark.c].push(shark);
    }
}

void eatShark(vector<vector<priority_queue<Shark, vector<Shark>, compare>>> &board) {
    for (int i = 1; i < board.size(); i++) {
        for (int j = 1; j < board[i].size(); j++) {
            while (board[i][j].size() > 1) {
                board[i][j].pop();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C >> M;
    vector<vector<priority_queue<Shark, vector<Shark>, compare>>> board(R + 1, vector<priority_queue<Shark, vector<Shark>, compare>>(C + 1));
    for (int i = 0; i < M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        int realS;
        if (d <= 2) {
            realS = s % (2 * R - 2);
        } else {
            realS = s % (2 * C - 2);
        }
        board[r][c].push(Shark(r, c, realS, d, z));
    }
    int sharkCount = 0;
    for (int fisherman = 0; fisherman < C; ) {
        fisherman++;
        sharkCount += findShark(board, fisherman);
        moveShark(board);
        eatShark(board);
    }
    cout << sharkCount;
    return 0;
}