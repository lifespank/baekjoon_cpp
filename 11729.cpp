#include <iostream>

using namespace std;

void hanoi(int n, int source, int aux, int target) {
    if (n == 1) {
        cout << source << ' ' << target << '\n';
        return;
    }
    hanoi(n - 1, source, target, aux);
    cout << source << ' ' << target << '\n';
    hanoi(n - 1, aux, source, target);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << (1 << n) - 1 << '\n';
    hanoi(n, 1, 2, 3);
    return 0;
}