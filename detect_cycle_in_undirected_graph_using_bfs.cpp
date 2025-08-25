#include<bits/stdc++.h>
using namespace std;

vector<int> adjList[105];
bool vis[105];
int parent[105];

bool isCycle = false;

void bfs(int src) {
    queue<int> q;

    q.push(src);

    vis[src] = true;

    while(!q.empty()) {
        int front = q.front();

        q.pop();

        for(int ch : adjList[front]) {

        if(vis[ch] && parent[front] != ch) {
            isCycle = true;
        }

        if(!vis[ch]) {
            q.push(ch);
            vis[ch] = true;
            parent[ch] = front;
        }
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
            bfs(i);
        }
    }

    if(isCycle) 
        cout << "YES" << endl;
    else   
        cout << "NO" << endl;
    
    return 0;
}