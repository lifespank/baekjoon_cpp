#include <iostream>
#define PRIME 1000000007

using namespace std;

int M;

long long myPow(long long x, long long p) {
  if (p == 0) return 1;
  if (p == 1) return x;
  
  if(p & 1) {
      return x * myPow(x, p - 1) % PRIME;
  }
  long long res = myPow(x, p / 2);
  return res * res % PRIME;
}

long long gcd(long long a, long long b) {
    if(b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

int main() {
    cin >> M;
    long long ans = 0;
    for(int i = 0; i < M; i++) {
        long long a, b;
        cin >> b >> a;
        long long g = gcd(a, b);
        b /= g;
        a /= g;
        ans += a * myPow(b, PRIME - 2) % PRIME;
        ans %= PRIME;
    }
    cout << ans;
    return 0;
}