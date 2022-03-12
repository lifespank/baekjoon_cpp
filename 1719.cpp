#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <deque>
#define INF 1e8
using namespace std;
int n, m, start, dest;
vector<pair<int, int>> graph[1001];
int dist[1001];
int prevVisited[1001];
int first[1001][1001];
deque<int> path;
void makePath(int num) {
    if(num != 0) {
        path.push_back(num);
        makePath(prevVisited[num]);
    }
}

void dijkstra(int start, int dest) {
    fill(dist, dist + 1001, INF);
    memset(prevVisited, 0, sizeof(prevVisited));
    dist[start] = 0;
    priority_queue<pair<int, int>> q;
    q.push({-dist[start], start});
    while(!q.empty()) {
        int here = q.top().second;
        q.pop();
        for(int i = 0; i < graph[here].size(); i++) {
            int next = graph[here][i].first;
            int nextCost = graph[here][i].second;
            if(dist[next] > dist[here] + nextCost) {
                dist[next] = dist[here] + nextCost;
                q.push({-dist[next], next});
                prevVisited[next] = here;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int from, to, val;
        cin >> from >> to >> val;
        bool plzAdd = true;
        for(int i = 0; i < graph[from].size(); i++) {
            if(graph[from][i].first == to) {
                plzAdd = false;
                if(graph[from][i].second > val) { //입력받은 비용이 더 작을 시 수정
                    graph[from][i].second = val;
                }
                break;
            }
        }
        for(int i = 0; i < graph[to].size(); i++) {
            if(graph[to][i].first == from) {
                plzAdd = false;
                if(graph[to][i].second > val) { //입력받은 비용이 더 작을 시 수정
                    graph[to][i].second = val;
                }
                break;
            }
        }
        if(plzAdd) {
            graph[from].push_back({to, val});
            graph[to].push_back({from, val});
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            dijkstra(i, j);
            makePath(j);
            if (path.size() >= 3) {
                first[i][j] = path[path.size() - 2];
                first[j][i] = path[1];
            } else {
                first[i][j] = j;
                first[j][i] = i;
            }
            path.clear();
        }
        cout << "\n";
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                cout << "- ";
            } else {
                cout << first[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}