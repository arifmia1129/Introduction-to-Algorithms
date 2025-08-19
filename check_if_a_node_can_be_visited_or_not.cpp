#include<bits/stdc++.h>
using namespace std;
vector<int> adjListArr[1005];
bool vis[1005];


void bfs(int src) {
    queue<int> q;

    q.push(src);

    while(!q.empty()) {
        int par = q.front();

        q.pop();

        for(int ch : adjListArr[par]) {
            if(!vis[ch]) {
                vis[ch] = true;
                q.push(ch);
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

    int s, d;

    cin >> s >> d;

    bfs(s);

    if(vis[d]) 
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
    
    return 0;
}