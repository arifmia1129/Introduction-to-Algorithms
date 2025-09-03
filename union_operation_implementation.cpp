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
    }else{
        parent[lead1] = lead2;
        groupSize[lead2] += groupSize[lead1];
    }
}

int main () {
    memset(parent, -1, sizeof(parent));
    memset(groupSize, 1, sizeof(groupSize));

    disJointUnion(1, 2);
    disJointUnion(2, 0);
    disJointUnion(3, 1);

    for(int i = 0; i < 6; i++) {
        cout << i << "-> " << parent[i] << endl;
    }
    
    return 0;
}