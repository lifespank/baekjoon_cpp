#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int maxVal = 0;

bool canRead(int word, int learned) {
    return !(word & ~learned);
}

void comb(vector<int>& words, int idx, int selected, int K, int learned) {
    if (learned & (1 << idx)) {
        comb(words, idx + 1, selected, K, learned);
        return;
    }
    if (selected == K) {
        int count = 0;
        for (auto& word: words) {
            if (canRead(word, learned)) {
                count++;
            }
        }
        maxVal = max(maxVal, count);
        return;
    }
    if (idx > 25) {
        return;
    }
    comb(words, idx + 1, selected + 1, K, learned | (1 << idx));
    comb(words, idx + 1, selected, K, learned);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    vector<int> words(N, 0);
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        for (auto &ch: word) {
            words[i] = words[i] | (1 << (ch - 'a'));
        }
    }
    comb(words, 0, 5, K, 532741);
    cout << maxVal;
    return 0;
}