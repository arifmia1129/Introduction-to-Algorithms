#include<bits/stdc++.h>
using namespace std;
vector<int> adjListArr[105];
bool vis[105];

void dfs(int src) {
    // cout << src << " ";

    for(int ch : adjListArr[src]) {
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

        adjListArr[a].push_back(b);
        adjListArr[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));

    int cnt = 0;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
             dfs(i);
            //  cout << endl;
            cnt++;
        }
    }

    cout << cnt;

    
    return 0;
}