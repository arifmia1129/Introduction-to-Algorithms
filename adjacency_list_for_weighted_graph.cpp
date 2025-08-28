#include<bits/stdc++.h>
using namespace std;


int main () {
    int n, e; cin >> n >> e;

    vector<pair<int, int>> adjList[n];

    while(e--) {
        int a, b, c; cin >> a >> b >> c;

        adjList[a].push_back({b, c});
        adjList[b].push_back({a, c});
    }

    for(int i = 0; i < n; i++) {
        cout << i << "---> ";

        for(auto p : adjList[i]) {
            cout << p.first << "," << p.second << "  ";
        }

        cout << endl;
    }
    
    return 0;
}