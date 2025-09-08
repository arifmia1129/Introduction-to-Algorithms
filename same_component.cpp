#include<bits/stdc++.h>
using namespace std;

int parent[105];
int groupSize[105];

int find(int node) {
    if(parent[node] == -1) return node;

    int lead = find(parent[node]);

    parent[node] = lead;

    return lead;
}

void disJointUnion(int node1, int node2) {
    int lead1 = find(node1);
    int lead2 = find(node2);

    if(groupSize[lead1] >= groupSize[lead2]) {
        parent[lead2] = lead1;
        groupSize[lead1] += groupSize[lead2];
    }else {
        parent[lead1] = lead2;
        groupSize[lead2] += groupSize[lead1];
    }
}


int main () {
    int n, e; cin >> n >> e;

    memset(parent, -1, sizeof(parent));
    memset(groupSize, 1, sizeof(groupSize));

    while(e--) {
        int a, b; cin >> a >> b;

        int lead1 = find(a);
        int lead2 = find(b);

        if(lead1 != lead2) {
            disJointUnion(a, b);
        }
    }

    bool isConnected = true;

    int lead1 = find(1);
    int cnt = 0;

    for(int i = 1; i <= n; i++) {
        int lead = find(i);

        if(lead1 != lead) {
            cnt++;
        }
    }

    if(isConnected) 
        cout << cnt << "Same component" << endl;
    else    
        cout << "Not same component" << endl;
    
    return 0;
}