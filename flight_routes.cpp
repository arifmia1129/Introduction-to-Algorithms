#include<bits/stdc++.h>
using namespace std;

#define ll long long int

vector<pair<int, int>> adjList[100005];
// int dis[105];
vector<ll> dis[100005];

int n, e, k;

void dijkstra(int src) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    
    pq.push({0, src});

    dis[src][0] = 0;

    while(!pq.empty()) {
        auto parent = pq.top();
        pq.pop();

        int parent_node = parent.second;
        int parent_dis = parent.first;

        for(auto ch : adjList[parent_node]) {
            int ch_node = ch.first;
            int ch_dis = ch.second;

            if(parent_dis + ch_dis < dis[ch_node][k - 1]) {
                dis[ch_node][k - 1] = parent_dis + ch_dis;

                pq.push({dis[ch_node][k - 1], ch_node});

                sort(dis[ch_node].begin(), dis[ch_node].end());
            }
        }
    }

}

int main () {
    cin >> n >> e >> k;

    while(e--) {
        int a, b, c; cin >> a >> b >> c;

        adjList[a].push_back({b, c});
    }

    for(int i = 1; i <= n; i++){
        dis[i].resize(k);
        for(int j = 0; j < k; j++) {
            dis[i][j] = 1e18;
        }
    }

    dijkstra(1);

    for (long long int ele : dis[n])
    {
        cout << ele << " ";
    }

    return 0;
}