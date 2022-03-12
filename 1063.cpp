#include <iostream>
#include <string>
using namespace std;

char kingX, kingY, stoneX, stoneY;

bool isInBoard(char x, char y) {
    return x >= 'A' && x <= 'H' && y >= '1' && y <= '8';
}

pair<char, char> move(char X, char Y, string str) {
    if(str.find('R') != string::npos) {
        X++;
    }
    if(str.find('L') != string::npos) {
        X--;
    }
    if(str.find('B') != string::npos) {
        Y--;
    }
    if(str.find('T') != string::npos) {
        Y++;
    }
    return {X, Y};
}


int main() {
    int opr;
    string tmp;
    cin >> tmp;
    kingX = tmp[0];
    kingY = tmp[1];
    cin >> tmp;
    stoneX = tmp[0];
    stoneY = tmp[1];
    cin >> opr;
    for(int i = 0; i < opr; i++) {
        cin >> tmp;
        pair<char, char> kingPos = move(kingX, kingY, tmp);
        pair<char, char> stonePos;
        if(kingPos.first == stoneX && kingPos.second == stoneY) {
            stonePos = move(stoneX, stoneY, tmp);
        }
        else {
            stonePos.first = stoneX;
            stonePos.second = stoneY;
        }
        if(isInBoard(kingPos.first, kingPos.second) && isInBoard(stonePos.first, stonePos.second)) {
            kingX = kingPos.first;
            kingY = kingPos.second;
            stoneX = stonePos.first;
            stoneY = stonePos.second;
        }
    }
    cout << kingX << kingY << '\n' << stoneX << stoneY;
    return 0;
}