#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
        int a, b, c;

        Edge(int a, int b, int c) {
            this->a = a;
            this->b = b;
            this->c = c;
        }
};

int n, e;

int dis[1005];
vector<Edge> edgeList;

void bellmanFord() {
    for(int i = 0; i < n - 1; i++) {
        for(auto ed : edgeList) {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;

            if(dis[a] != INT_MAX && dis[a] + c < dis[b]) {
                dis[b] = dis[a] + c;
            }
        }
    }

    bool isCycle = false;

    for(auto ed : edgeList) {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;

            if(dis[a] != INT_MAX && dis[a] + c < dis[b]) {
                isCycle = true;
            }
        }

    if(isCycle) {
        cout << "Negative weighted cycle detected!" << endl;
    }else {
        for(int i = 0; i < n; i++) {
        cout << i << "---> " << dis[i] << endl;
    }
    }
}


int main () {
    

    cin >> n >> e;


    while(e--) {
        int a, b, c;

        cin >> a >> b >> c;

        edgeList.push_back(Edge(a, b, c));
    }

    for(int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    dis[0] = 0;

    bellmanFord();
    
    return 0;
}