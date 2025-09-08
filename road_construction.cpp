#include<bits/stdc++.h>
using namespace std;

int parent[100005];
int groupSize[100005];

int cmp;
int mx;

int find(int node) {
    if(parent[node] == -1) return node;

    int lead = find(parent[node]);

    parent[node] = lead;

    return lead;
}

void makeUnion(int node1, int node2) {
    int lead1 = find(node1);
    int lead2 = find(node2);

    if(lead1 == lead2)
        return;

    if(groupSize[lead1] >= groupSize[lead2]){
        parent[lead2] = lead1;
        groupSize[lead1] += groupSize[lead2];

        mx = max(mx, groupSize[lead1]);
    }else{
        parent[lead1] = lead2;
        groupSize[lead2] += groupSize[lead1];

        mx = max(mx, groupSize[lead2]);
    }

    cmp--;
}


int main () {
    int n, e; cin >> n >> e;

    cmp = n;

    for(int i = 1; i <= n; i++) {
        parent[i] = -1;
        groupSize[i] = 1;
    }

    while(e--) {
        int a, b; cin >> a >> b;

        makeUnion(a, b);

        cout << cmp << " " << mx << endl;
    }
    
    return 0;
}