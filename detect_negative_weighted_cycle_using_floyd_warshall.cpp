#include<bits/stdc++.h>
using namespace std;

int main () {
    int n, e;

    cin >> n >> e;

    int adjMat[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                adjMat[i][j] = 0;
            }else{
                adjMat[i][j] = INT_MAX;
            }
        }
    }

    while(e--) {
        int a, b, c;

        cin >> a >> b >> c;

        adjMat[a][b] = c;
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(adjMat[i][k] != INT_MAX && adjMat[k][j] != INT_MAX && adjMat[i][k] + adjMat[k][j] < adjMat[i][j]) {
                    adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
                }
            }
        }
    }

    bool isCycle = false;

    for(int i = 0; i < n; i++) {
        if(adjMat[i][i] < 0) {
            isCycle = true;
        }
    }

    if(isCycle) {
        cout << "Negative weighted cycle detected" << endl;
    }else {
        for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(adjMat[i][j] == INT_MAX){
                cout << "INT" << " ";
            }else{
                cout << adjMat[i][j] << " ";
            }
        }
        cout << endl;
    }
    }

    return 0;
}