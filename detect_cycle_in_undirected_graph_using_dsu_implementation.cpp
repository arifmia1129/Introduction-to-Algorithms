#include<bits/stdc++.h>
using namespace std;
int parent[100005];
int groupSize[100005];

int find(int node) {
    if(parent[node] == -1) return node;

    int lead = find(parent[node]);

    parent[node] = lead;

    return lead;
}

void disJointUnion(int lead1, int lead2) {
    if(groupSize[lead1] >= groupSize[lead2]) {
        parent[lead2] = lead1;
        groupSize[lead1] += groupSize[lead2];
    }else{
        parent[lead1] = lead2;
        groupSize[lead2] += groupSize[lead1];
    }
}

int main () {
    int n, e; cin >> n >> e;


    memset(parent, -1, sizeof(parent));
    memset(groupSize, 1, sizeof(groupSize));

    int cnt = 0;

    while(e--) {
        int a, b; cin >> a >> b;

        int lead1 = find(a);
        int lead2 = find(b);

        if(lead1 == lead2) {
            cnt++;
        }else{
            disJointUnion(lead1, lead2);
        }
    }

    cout << cnt << endl;

    return 0;
}