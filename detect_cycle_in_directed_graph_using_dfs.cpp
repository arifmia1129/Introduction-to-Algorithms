#include<bits/stdc++.h>
using namespace std;

vector<int> adjList[105];
bool vis[105];
bool pathvis[105];

bool isCycle = false;

void dfs(int src) {
    vis[src] = true;
    pathvis[src] = true;

    for(int ch : adjList[src]) {
        if(vis[ch] && pathvis[ch])
            isCycle = true;

        if(!vis[ch]) {
            dfs(ch);
        }
    }

    pathvis[src] = false;
}

int main () {
    int n, e; cin >> n >> e;

    while(e--) {
        int a, b; cin >> a >> b;

        adjList[a].push_back(b);
    }

    memset(vis, false, sizeof(vis));
    memset(pathvis, false, sizeof(pathvis));

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