#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

class Face {
    public:
    vector<vector<char>> color;
    class Face* up;
    class Face* down;
    class Face* left;
    class Face* right;
    Face(char c) {
        color.push_back(vector<char>(3, c));
        color.push_back(vector<char>(3, c));
        color.push_back(vector<char>(3, c));
    }
    void setNeighbors(Face* u, Face* d, Face* l, Face* r) {
        up = u;
        down = d;
        left = l;
        right = r;
    }
    void turnRight() {
        vector<vector<char>> temp = color;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                color[i][j] = temp[2 - j][i];
            }
        }
        up->from(left);
        down->from(right);
        left->from(down);
        right->from(up);
    }
    void turnLeft() {
        vector<vector<char>> temp = color;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                color[i][j] = temp[j][2 - i];
            }
        }
        up->from(right);
        down->from(left);
        left->from(up);
        right->from(down);
    }
    void from(Face* fromFace) {
        for(int i = 0; i < 3; i++) {
            color[0][i] = fromFace->color[0][i];
        }
    }
    void printFace() {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cout << color[i][j];
            }
            cout << "\n";
        }
    }
};

int testCase, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> testCase;
    for(int tc = 0; tc < testCase; tc++) {
        vector<pair<char, char>> rots;
        cin >> n;
        for(int i = 0; i < n; i++) {
            string str;
            cin >> str;
            rots.push_back({str[0], str[1]});
        }
        Face U = Face('w');
        Face D = Face('y');
        Face F = Face('r');
        Face B = Face('o');
        Face L = Face('g');
        Face R = Face('b');
        U.setNeighbors(&B, &F, &L, &R);
        D.setNeighbors(&B, &F, &R, &L);
        U.setNeighbors(&B, &F, &L, &R);
        U.setNeighbors(&B, &F, &L, &R);
        U.setNeighbors(&B, &F, &L, &R);
        U.setNeighbors(&B, &F, &L, &R);
    }
    return 0;
}