# Question 19: 0/1 Knapsack Problem

## Problem Statement
You have n items, each with a weight and value. You have a knapsack with capacity W. Find the maximum value you can obtain by selecting items such that their total weight doesn't exceed W.

## Input Format
- First line contains n (number of items) and W (knapsack capacity)
- Next n lines contain weight and value of each item

## Constraints
- 1 ≤ n ≤ 100
- 1 ≤ W ≤ 1000
- 1 ≤ weight, value ≤ 100

## Output Format
Print the maximum value achievable

## Sample Input 0
```
4 5
1 1
3 4
4 5
5 7
```

## Sample Output 0
```
9
```

## Solution (Top-Down DP with Memoization)

```cpp
#include<bits/stdc++.h>
using namespace std;

int n, W;
vector<int> weight, value;
int dp[105][1005];

int knapsack(int i, int w) {
    if(i == n || w == 0) return 0;
    
    if(dp[i][w] != -1) return dp[i][w];
    
    int ans = knapsack(i + 1, w);
    
    if(weight[i] <= w) {
        ans = max(ans, knapsack(i + 1, w - weight[i]) + value[i]);
    }
    
    return dp[i][w] = ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> W;
    
    weight.resize(n);
    value.resize(n);
    
    for(int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << knapsack(0, W) << "\n";
    
    return 0;
}
```

## Solution (Bottom-Up DP)

```cpp
#include<bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, W; cin >> n >> W;
    
    vector<int> weight(n + 1), value(n + 1);
    
    for(int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }
    
    int dp[n + 1][W + 1];
    
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if(weight[i] <= w) {
                dp[i][w] = max(value[i] + dp[i - 1][w - weight[i]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    cout << dp[n][W] << "\n";
    
    return 0;
}
```

## Time Complexity: O(n × W)
## Space Complexity: O(n × W)

## Approach
Dynamic Programming approach where dp[i][w] represents maximum value achievable using first i items with weight limit w. For each item, we have two choices: include it or exclude it. We take the maximum of both choices.