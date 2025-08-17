#include<bits/stdc++.h>
using namespace std;

int main () {
    int n, e;

    cin >> n >> e;

    int adjMatArr[n][n];

    memset(adjMatArr, 0, sizeof(adjMatArr));

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++)
            if(i == j)
                adjMatArr[i][j] = 1;

    while(e--) {
        int a, b;

            cin >> a >> b;

            adjMatArr[a][b] = 1;
            adjMatArr[b][a] = 1;
        
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << adjMatArr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}