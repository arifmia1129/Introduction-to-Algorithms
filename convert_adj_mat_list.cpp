#include<bits/stdc++.h>
using namespace std;

int main () {
    int n;

    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int>> adjList(n, vector<int>());

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == 1) {
                adjList[i].push_back(j);
            }
        }
    }

    cout << endl;

    for(int i = 0; i < n; i++) {
        cout << i << " -> ";
        for(int val : adjList[i]) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << endl;

    vector<vector<int>> mat2(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int val : adjList[i]) {
            mat2[i][val] = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << mat2[i][j] << " ";
        }

        cout << endl;
    }
    
    return 0;
}