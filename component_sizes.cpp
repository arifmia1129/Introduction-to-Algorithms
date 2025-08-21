#include<bits/stdc++.h>
using namespace std;

vector<int> adjListArr[1005];
bool vis[1005];
int cnt = 0;

void dfs(int src) {
    vis[src] = true;

    cnt++;

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

    vector<int> numsOfNode;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
        if(cnt > 0) {
            numsOfNode.push_back(cnt);
            cnt = 0;
        }
    }

    sort(numsOfNode.begin(), numsOfNode.end());


    for(int x : numsOfNode) {
        cout << x <<  " ";
    }

    return 0;
}