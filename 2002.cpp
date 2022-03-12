#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int N;
unordered_map<string, int> yeongsik;
vector<string> daegeun;
int main() {
    cin >> N;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        yeongsik.insert({tmp, i});
    }
    for(int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        daegeun.push_back(tmp);
    }
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(yeongsik[daegeun[i]] > yeongsik[daegeun[j]]) {
                ans++;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}