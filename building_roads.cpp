#include<bits/stdc++.h>
using namespace std;

void dfs(int src,  vector<vector<int>> &adjList,  vector<bool> &visited) {
    visited[src] = true;

    for(int ch : adjList[src]) {
        if(!visited[ch]) {
            dfs(ch, adjList, visited);
        }
    }
}

int main () {
    int n, m; cin >> n >> m;

    vector<vector<int>> adjList(n + 1);
    vector<bool> visited(n + 1);

    while(m--) {
        int a, b; cin >> a >> b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    vector<int> result;

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            result.push_back(i);
            dfs(i, adjList, visited);
        }
    }
    
    int sz = result.size();

    cout << sz - 1 << endl;

    for(int i = 0; i < sz - 1; i++) {
        cout << result[i] << " " << result[i + 1] << endl;
    }

    return 0;
}