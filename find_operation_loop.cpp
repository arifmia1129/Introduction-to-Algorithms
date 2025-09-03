#include<bits/stdc++.h>
using namespace std;

int parent[1005];

int findParent(int node) {
    while(parent[node] != -1) {
        node = parent[node];
    }

    return node;
}

int main () {
    memset(parent, -1, sizeof(parent));

    parent[0] = 1;
    parent[1] = -1;
    parent[2] = 1;
    parent[3] = 1;
    parent[4] = 5;  
    parent[5] = 3;

    cout << findParent(4) << endl;
    
    return 0;
}