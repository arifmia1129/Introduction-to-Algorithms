#include<bits/stdc++.h>
using namespace std;

long long int dis[10005];

class Edge{
    public:
        int a, b, c;

        Edge(int a, int b, int c) {
            this->a = a;
            this->b = b;
            this->c = c;
        }
};

vector<Edge> edgeList;


int main () {
    int n, e; cin >> n >> e;

    long long int max_val = 1e17;

    for(int i = 1; i <= n; i++) {
        dis[i] = max_val;
    }

    while(e--) {
        int a, b, c; cin >> a >> b >> c;

        edgeList.push_back(Edge(a, b, c));
    }

    int src; cin >> src;

    dis[src] = 0;

    for(int i = 1; i <= n; i++) {
        for(auto ed : edgeList) {
            int a = ed.a;
            int b = ed.b;
            int c = ed.c;

            if(dis[a] != max_val && dis[a] + c < dis[b]) {
                dis[b] = dis[a] + c;
            }
        }
    }

    bool isCycle = false;

    for(auto ed : edgeList) {
            int a = ed.a;
            int b = ed.b;
            int c = ed.c;

            if(dis[a] != max_val && dis[a] + c < dis[b]) {
                dis[b] = dis[a] + c;
                isCycle = true;
            }
    }

    if(isCycle) {
        cout << "Negative Cycle Detected" << endl;
    }else{
        int t; cin >> t;
        
        while(t--) {
            int d; cin >> d;

            if(dis[d] == max_val) 
                cout << "Not Possible" << endl;
            else
                cout << dis[d] << endl;
        }
    }
    
    return 0;
}