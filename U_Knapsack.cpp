#include<bits/stdc++.h>
using namespace std;

int weight[1005];
int val[1005];
int dp[1005][1005];

int knapsack(int i, int maxVal) {
    if(i < 0 || maxVal <= 0) return 0;

    if(dp[i][maxVal] != -1) return dp[i][maxVal];

    if(weight[i] <= maxVal) {
        int op1 = knapsack(i - 1, maxVal - weight[i]) + val[i];
        int op2 = knapsack(i - 1, maxVal);

        dp[i][maxVal] = max(op1, op2);

        return dp[i][maxVal];
    }else{
        dp[i][maxVal] = knapsack(i - 1, maxVal);

         return dp[i][maxVal];
    }
}

int main () {
    int n, maxVal; cin >> n >> maxVal;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= maxVal; j++)
            dp[i][j] = -1;
    }

    for(int i = 0; i < n; i++) {
        cin >> weight[i] >> val[i];
    }

    cout << knapsack(n - 1, maxVal) << endl;
    
    return 0;
}