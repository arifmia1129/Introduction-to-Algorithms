#include<bits/stdc++.h>
using namespace std;
vector<int> adjListArr[1005];
bool vis[1005];

void bfs(int src) {
    queue<int> q;

    q.push(src);

    vis[src] = true;

    while(!q.empty()) {
        int parent = q.front();

        q.pop();

        cout << parent << " ";

        for(int x : adjListArr[parent]) {
            if(!vis[x]) {
                q.push(x);
                vis[x] = true;
            }
        }
        
    }
}

int main () {
    int n, e;

    cin >> n >> e;

    memset(vis, false, sizeof(vis));

    while(e--) {
        int a, b;

        cin >> a >> b;

        adjListArr[a].push_back(b);
        adjListArr[b].push_back(a);
    }

    bfs(0);

    return 0;
}