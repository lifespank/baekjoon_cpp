#include <iostream>
#include <vector>

using namespace std;

bool visited[2000001];

void comb(vector<int>& S, int sum, int idx) {
    if (idx == S.size()) {
        visited[sum] = true;
        return;
    }
    comb(S, sum + S[idx], idx + 1);
    comb(S, sum, idx + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    comb(S, 0, 0);
    for (int i = 1; i <= 2000000; i++) {
        if (!visited[i]) {
            cout << i;
            break;
        }
    }

    return 0;
}