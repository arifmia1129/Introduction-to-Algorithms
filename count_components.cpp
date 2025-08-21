#include<bits/stdc++.h>
using namespace std;
vector<int> adjListArr[1005];
bool vis[1005];

void dfs(int src) {
    vis[src] = true;

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

    int cnt = 0;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            cnt++;
            dfs(i);
        }
    }

    cout << cnt;

    return 0;
}