#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int ans[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int howMany;
        cin >> howMany;
        for(int j = 0; j < N; j++) {
            if(!howMany && !ans[j]) {
                ans[j] = i + 1;
                break;
            }
            else if(!ans[j]) {
                howMany--;
            }
        }
    }
    for(int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}