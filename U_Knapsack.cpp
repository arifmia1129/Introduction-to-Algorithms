#include<bits/stdc++.h>
using namespace std;
int val[1005];
int weight[1005];
int dp[1005][1005];

int knapsack(int i, int maxWeight) {
    if(i < 0 || maxWeight <= 0)
        return 0;
    
    if(dp[i][maxWeight] != -1)
        return dp[i][maxWeight];

    if(weight[i] <= maxWeight) {
        int op1 = knapsack(i - 1, maxWeight - weight[i]) + val[i];
        int op2 = knapsack(i - 1, maxWeight);

        dp[i][maxWeight] = max(op1, op2);

        return dp[i][maxWeight];
    }else{
        dp[i][maxWeight] = knapsack(i - 1, maxWeight);

        return dp[i][maxWeight];
    }
}


int main () {
    int n, maxWeight; 
    cin >> n >> maxWeight;

     for(int i = 0; i < n; i++) {
        for(int j = 0; j <= maxWeight; j++){
            dp[i][j] = -1;
        }
    }

    for(int i = 0; i < n; i++){
        cin >> weight[i] >> val[i];
    }

   

    cout << knapsack(n - 1, maxWeight);
    
    return 0;
}