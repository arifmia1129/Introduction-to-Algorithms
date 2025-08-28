#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adjList[105];
int dis[105];

void dijkstra(int src) {
    queue<pair<int, int>> q;
    q.push({0, 0});

    dis[src] = 0;

    while(!q.empty()) {
        auto parent = q.front();
        q.pop();

        int par_node = parent.first;
        int par_dis = parent.second;

        for(auto ch : adjList[par_node]) {
            int ch_node = ch.first;
            int ch_dis = ch.second;

            if(ch_dis + par_dis  < dis[ch_node]) {
                dis[ch_node] = ch_dis + par_dis;
                q.push({ch_node, ch_dis + par_dis});
            }
        }
    }
}

int main () {
    int n, e; cin >> n >> e;

    while(e--){
        int a, b, c; cin >> a >> b >> c;

        adjList[a].push_back({b, c});
        adjList[b].push_back({a, c});
    }

    for(int i = 0; i < n; i++)
        dis[i] = INT_MAX;
    
    dijkstra(0);

    for(int i = 0; i < n; i++) {
        cout << i << " " << dis[i] << endl;
    }

    return 0;
}