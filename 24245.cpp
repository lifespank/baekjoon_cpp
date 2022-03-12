#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<string> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i];
    }
    
    return 0;
}