#include<bits/stdc++.h>
using namespace std;


int dp[35];

int tet(int n) {
    if(dp[n] != -1) return dp[n];

    dp[n] = tet(n - 1) + tet(n - 2) + tet(n - 3) + tet(n - 4);

    return dp[n];
}

int main () {
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;


    cout << tet(n) << endl;


    return 0;
}