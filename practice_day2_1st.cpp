#include<bits/stdc++.h>
using namespace std;

vector<int> adjList[1005];
bool vis[1005];

vector<int> totalNodes;

void dfs(int src) {
    totalNodes.push_back(src);

    vis[src] = true;

    for(int ch : adjList[src]) {
        if(!vis[ch]) {
            vis[ch] = true;
            dfs(ch);
        }
    }
}


int main () {
    int n, e;

    cin >> n >> e;

   

    while(e--) {
        int a, b;

        cin >> a >> b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    int q; cin >> q;

    memset(vis, false, sizeof(vis));

    dfs(q);

    cout << totalNodes.size();

    return 0;
}