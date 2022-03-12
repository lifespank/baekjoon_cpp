#include <iostream>

using namespace std;

long long getCounts(int n, int digit) {
    long long count = 0;
    long long pow = 1;
    while (n > 0) {
        int base = n / 10;
        if (digit <= n % 10) {
            base++;
        }
        count += base * pow;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
        pow *= 10;
        n /= 10;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i <= 9; i++) {
        cout << getCounts(n, i) << ' ';
    }
    return 0;
}