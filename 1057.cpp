#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, kim, lim;
    cin >> n >> kim >> lim;
    int count = 0;
    while (kim > 0 && lim > 0 && kim != lim) {
        kim = (kim + 1) / 2;
        lim = (lim + 1) / 2;
        count++;
    }
    if (kim == 0 || lim == 0) {
        count = -1;
    }
    cout << count;
    return 0;
}