#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int n, m;
int mat[11][11];
int dp[11][11];

int rec(int i, int j) {
    if(i >= n || j >= m) return INT_MIN;

    if(i == n - 1 && j == m - 1) return mat[i][j];

    if(dp[i][j] != -1) return dp[i][j];

    int right = rec(i, j + 1);
    int down = rec(i + 1, j);

    dp[i][j] = mat[i][j] + max(right, down);

    return dp[i][j];
}



int main () {
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];

    memset(dp, -1, sizeof(dp));
    
    cout << rec(0, 0) << endl;

    return 0;
}