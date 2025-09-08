#include<bits/stdc++.h>
using namespace std;

int main () {
   long long int n, e, q; cin >> n >> e;

   long long int adjMat[n + 5][n + 5];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                adjMat[i][j] = 0;
            }else {
                adjMat[i][j] = LLONG_MAX;
            }
        }
    }

    while(e--) {
        long long a, b, c; cin >> a >> b >> c;

        adjMat[a][b] = min(adjMat[a][b], c);
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <=n; i++) {
            for(int j = 1; j <=n; j++) {
                if(adjMat[i][k] != LLONG_MAX && adjMat[k][j] != LLONG_MAX && adjMat[i][k] + adjMat[k][j] < adjMat[i][j]) {
                    adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
                }
            }
        }
    }    

    cin >> q;

    while(q--) {
        int s, d; cin >> s >> d;

        if(adjMat[s][d] == LLONG_MAX) 
            cout << -1 << endl;
        else 
            cout << adjMat[s][d] << endl;
    }

    return 0;
}