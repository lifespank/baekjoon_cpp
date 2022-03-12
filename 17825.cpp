#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    int score;
    Node* next;
    int horses;
    Node(int s, Node* n) {
        score = s;
        next = n;
        horses = 0;
    }
    

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}