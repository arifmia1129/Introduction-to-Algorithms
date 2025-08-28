#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adjList[105];
int dis[105];

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, src});

    dis[src] = 0;

    while(!pq.empty()) {
        auto parent = pq.top();
        pq.pop();

        int parent_node = parent.second;
        int parent_dis = parent.first;

        for(auto ch : adjList[parent_node]) {
            int ch_node = ch.first;
            int ch_dis = ch.second;

            if(parent_dis + ch_dis < dis[ch_node]) {
                dis[ch_node] = parent_dis + ch_dis;

                pq.push({parent_dis + ch_dis, ch_node});
            }
        }
    }

}

int main () {
    int n, e; cin >> n >> e;

    while(e--) {
        int a, b, c; cin >> a >> b >> c;

        adjList[a].push_back({b, c});
        adjList[b].push_back({a, c});
    }

    for(int i = 0; i < n; i++) 
        dis[i] = INT_MAX;

    dijkstra(0);

    for(int i = 0; i < n; i++) {
        cout << i << " -> " << dis[i] << endl;
    }

    return 0;
}