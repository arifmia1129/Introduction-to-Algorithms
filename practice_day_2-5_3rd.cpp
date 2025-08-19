#include<bits/stdc++.h>
using namespace std;


int main () {
    int n, e;

    cin >> n >> e;

    vector<int> adjListArr[1005];


    while(e--) {
        int a, b;

        cin >> a >> b;

        adjListArr[a].push_back(b);
        adjListArr[b].push_back(a);
    }

    int node; cin >> node;

    cout << adjListArr[node].size();
    
    return 0;
}