#include<bits/stdc++.h>
using namespace std;

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
long long int dis[2505];

int main () {
    int n, m; cin >> n >> m;

    long long int maxVal = 1e17;

    while(m--) {
        int a, b, c; cin >> a >> b >> c;

        edgeList.push_back(Edge(a, b, (-1 * c)));
    }

    for(int i = 1; i <= n; i++)
        dis[i] = maxVal;

    dis[1] = 0;
    
    for(int i = 1; i < n; i++) {
        for(auto ed : edgeList) {
            int a = ed.a;
            int b = ed.b;
            int c = ed.c;

            if(dis[a] == maxVal) continue;

            dis[b] = min(dis[b], dis[a] + c);
        }
    }

    for(int i = 1; i <= n; i++) {
        for(auto ed : edgeList) {
             int a = ed.a;
            int b = ed.b;
            int c = ed.c;
            if(dis[a] == maxVal) continue;

            if(dis[a] + c < dis[b]) {
                dis[b] = -1 * maxVal;
            }
        }
    }

    if(dis[n] == -1 * maxVal) {
        cout << -1 << endl;
    }else {
        cout << -1 * dis[n] << endl;
    }

    return 0;
}