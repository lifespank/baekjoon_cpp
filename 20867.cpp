#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M, S, G, L, R;
    double A, B;
    cin >> M >> S >> G >> A >> B >> L >> R;
    double left = L / A + M / static_cast<double>(G);
    double right = R / B + M / static_cast<double>(S);
    if (left < right) {
        cout << "friskus";
    } else {
        cout << "latmask";
    }
    return 0;
}