#include<bits/stdc++.h>
using namespace std;

vector<int> adjList[105];
bool vis[105];
int parent[105];

bool isCycle = false;

void dfs(int src) {
    vis[src] = true;

    for(int ch : adjList[src]) {
        if(vis[ch] && parent[src] != ch)
            isCycle = true;

        if(!vis[ch]) {
            parent[ch] = src;
            dfs(ch);
        }
    }
}


int main () {
    int n, e; cin >> n >> e;

    while(e--) {
        int a, b; cin >> a >> b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    isCycle = false;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }

    if(isCycle)
        cout << "YES";
    else    
        cout << "NO";
    
    return 0;
}