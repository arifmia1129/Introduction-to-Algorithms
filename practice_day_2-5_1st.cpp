#include<bits/stdc++.h>
using namespace std;

vector<int> adjListArr[100005];
bool vis[100005];
int level[100005];
int parent[100005];

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

    int q;

    cin >> q;

    while(q--) {
        int s, d;

        cin >> s >> d;

        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));
        memset(parent, -1, sizeof(parent));

        bfs(s);

        cout << level[d] << endl;
    }
    
    return 0;
}