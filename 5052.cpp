#include <iostream>
#include <memory.h>

using namespace std;

struct TRIE {
    bool isEnd;
    TRIE *next[10];
    TRIE() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    ~TRIE() {
        for (int i = 0; i < 10; i++) {
            if (next[i]) {
                delete next[i];
            }
        }
    }
    void insert(char *str) {
        if (!*str) {
            isEnd = true;
        } else {
            int curr = *str - '0';
            if (next[curr] == NULL) {
                next[curr] = new TRIE();
            }
            next[curr]->insert(str + 1);
        } 
    }
    bool find(char *str){
		if(*str=='\0') {
            return false;
        }
		if(isEnd) {
            return true;
        }
		int idx = *str - '0';
		return next[idx]->find(str + 1);
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t-- > 0) {
        TRIE *root = new TRIE();
        int n;
        bool isBroken = false;
        cin >> n;
        char nums[10001][12];
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            root->insert(nums[i]);
        }
        for (int i = 0; i < n; i++) {
            if (root->find(nums[i])) {
                isBroken = true;
                break;
            }
        }
        if (!isBroken) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}