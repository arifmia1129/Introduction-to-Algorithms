#include<bits/stdc++.h>
using namespace std;
vector<int> adjListArr[1005];
bool vis[1005];

void dfs(int src) {
    cout << src <<  " ";

    vis[src] = true;

    for(int ch : adjListArr[src]) 
        if(!vis[ch])
            dfs(ch);
}

int main () {
    int n, e;

    cin >> n >> e;

    while(e--) {
        int a, b; cin >> a >> b;

        adjListArr[a].push_back(b);
        adjListArr[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));

    dfs(1);
    
    return 0;
}