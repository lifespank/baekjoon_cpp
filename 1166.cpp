#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    double l, w, h;
    scanf("%d %lf %lf %lf", &n, &l, &w, &h);
    double low = 0.0;
    double high = max({l, w, h});
    double mid;
    for (int i = 0; i < 1000; i++) {
        mid = low + (high - low) / 2;
        if ((long long)(l / mid) * (long long)(w / mid) * (long long)(h / mid) < n) {
            high = mid;
        } else {
            low = mid;
        }
    }
    printf("%.10f", low);
    return 0;
}