#include<bits/stdc++.h>
using namespace std;

#define ll long long int

vector<pair<ll, ll>> adjList[100005];
ll dis[100005];
ll parent[100005];


void dijkstra(ll src) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<int, int>>> pq;

    pq.push({0, src});

    dis[src] = 0;

    while(!pq.empty()) {
        auto front = pq.top();
        pq.pop();

        ll parentNode = front.second;
        ll parentDis = front.first;

        for(auto ch : adjList[parentNode]) {
            ll chNode = ch.first;
            ll chDis = ch.second;

            if(parentDis + chDis < dis[chNode]) {
                dis[chNode] = parentDis + chDis;

                pq.push({parentDis + chDis, chNode});

                parent[chNode] = parentNode;
            }
        }
    }
}




int main () {
    ll n, e; cin >> n >> e;

    while(e--) {
        ll a, b, c; cin >> a >> b >> c;

        adjList[a].push_back({b, c});
        adjList[b].push_back({a, c});
    }

    for(ll i = 1; i <=n; i++) {
        dis[i] = LLONG_MAX;
        parent[i] = -1;
    }

     dijkstra(1);

    if(dis[n] == LLONG_MAX)
        cout << -1 << endl;
    else{
        ll node = n;

        vector<int> path;

        while(node != -1) {
            path.push_back(node);
            node = parent[node];
        }

        reverse(path.begin(), path.end());

        for(auto x : path)
            cout << x << " ";

        cout << endl;
    }
    
    return 0;
}