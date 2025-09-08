#include<bits/stdc++.h>
using namespace std;

int parent[1005];
int groupSize[1005];


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
    }else{
        parent[lead1] = lead2;
        groupSize[lead2] += groupSize[lead1];
    }
}

vector<pair<int, int>> rmv;
vector<pair<int, int>> crt;


int main () {
    int n; cin >> n;


    for(int i = 1; i <= n; i++) {
        parent[i] = -1;
        groupSize[i] = 1;
    }

   for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;

        int lead1 = find(a);
        int lead2 = find(b);

        if(lead1 == lead2) {
            rmv.push_back({a, b});
        }else{
            makeUnion(a, b);
        }
   }

   for(int i = 2; i <= n; i++) {
        int initLead = find(1);
        int newLead = find(i);

        if(initLead != newLead) {
            crt.push_back({1, i});
            makeUnion(1, i);
        }
   }

   cout << rmv.size() << endl;

   for(int i = 0; i < rmv.size(); i++) {
    cout << rmv[i].first << " " << rmv[i].second << " " << crt[i].first << " " << crt[i].second << endl;
   }

   
    return 0;
}