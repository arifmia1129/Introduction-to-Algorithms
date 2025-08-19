#include<bits/stdc++.h>
using namespace std;

vector<int> adjListArr[1005];
bool vis[1005];
int level[1005];
int parent[1005];

void bfs(int src) {
    queue<int> q;

    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while(!q.empty()) {
        int par = q.front();

        q.pop();

        for(int ch : adjListArr[par]) {
            if(!vis[ch]) {
                q.push(ch);
                vis[ch] = true;
                level[ch] = level[par] + 1;
                parent[ch] = par;
            }
        }
    }
}

int main () {
    int n, e;

    cin >> n >> e;

    while(e--) {
        int a, b;

        cin >> a >> b;

        adjListArr[a].push_back(b);
        adjListArr[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    int s, d;

    cin >> s >> d;

    bfs(s);

    int node = d;
    
    vector<int> path;

    while(node != -1) {
        path.push_back(node);

        node = parent[node];
    }

    reverse(path.begin(), path.end());

    for(int x : path)
        cout << x << " ";
    
    return 0;
}