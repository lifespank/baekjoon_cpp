#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count = 0;
    int X;
    cin >> X;
    for (int i = 1; i <= X; i = i << 1) {
        if (i & X) {
            count++;
        }
    }
    cout << count;
    return 0;
}