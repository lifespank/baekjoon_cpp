#include <iostream>
#include <string>

using namespace std;

int main() {
    string L, R;
    cin >> L >> R;
    int eightCount = 0;
    if(L.size() == R.size()) {
        for(int i = 0; i < L.size(); i++) {
            if(L[i] == R[i] && R[i] == '8') {
                eightCount++;
            }
            if(L[i] != R[i]) {
                break;
            }
        }
    }
    cout << eightCount;
    return 0;
}