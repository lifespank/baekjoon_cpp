#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> moves[100];
int gear[4];

int twoPower(int n) {
    if(n == 0) {
        return 1;
    }
    if(n & 1) {
        return 2 * twoPower(n - 1);
    }
    else {
        return twoPower(n / 2) * twoPower(n / 2);
    }
}

void moveOneGear(int gearNum, int dir) {
    if(dir == 1) {
        int LSB = gear[gearNum] & 1;
        gear[gearNum] = (gear[gearNum] >> 1) | (LSB << 7);
    }
    else {
        int MSB = gear[gearNum] & (1 << 7);
        if(MSB) {
            MSB = 1;
        }
        gear[gearNum] = gear[gearNum] & 127;
        gear[gearNum] = (gear[gearNum] << 1) | MSB;
    }
}

void moveGearSet(int gearNum, int dir, char lr) {
    if(gearNum > 0 && (lr == 'l' || lr == 'b')) {
        int thisJoint = gear[gearNum] & 2;
        if(thisJoint) {
            thisJoint = 1;
        }
        int otherJoint = gear[gearNum - 1] & (1 << 5);
        if(otherJoint) {
            otherJoint = 1;
        }
        if(thisJoint ^ otherJoint) {
            moveGearSet(gearNum - 1, -dir, 'l');
        }
    }
    if(gearNum < 3 && (lr == 'r' || lr == 'b')) {
        int thisJoint = gear[gearNum] & (1 << 5);
        if(thisJoint) {
            thisJoint = 1;
        }
        int otherJoint = gear[gearNum + 1] & 2;
        if(otherJoint) {
            otherJoint =1;
        }
        if(thisJoint ^ otherJoint) {
            moveGearSet(gearNum + 1, -dir, 'r');
        }
    }
    moveOneGear(gearNum, dir);
}

int calcScore() {
    int total = 0;
    for(int i = 0; i < 4; i++) {
        if(gear[i] & (1 << 7)) {
            total += twoPower(i);
        }
    }
    return total;
}

int main() {
    int K;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 8; j++) {
            char c;
            c = getchar();
            if(c == '1') {
                gear[i] += twoPower(7 - j);
            }
        }
        getchar();
    }
    scanf("%d", &K);
    for(int i = 0; i < K; i++) {
        int gearNum, dir;
        scanf("%d %d", &gearNum, &dir);
        gearNum--;
        moveGearSet(gearNum, dir, 'b');
    }
    printf("%d", calcScore());
    return 0;
}