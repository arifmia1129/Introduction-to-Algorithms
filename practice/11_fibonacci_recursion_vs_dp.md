# Question 11: Fibonacci with Memoization

## Problem Statement
Calculate the nth Fibonacci number efficiently. The Fibonacci sequence is: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

Where F(0) = 0, F(1) = 1, and F(n) = F(n-1) + F(n-2) for n > 1.

## Input Format
- Single integer n

## Constraints
- 0 ≤ n ≤ 45

## Output Format
Print the nth Fibonacci number

## Sample Input 0
```
10
```

## Sample Output 0
```
55
```

## Sample Input 1
```
0
```

## Sample Output 1
```
0
```

## Solution (With Memoization)

```cpp
#include<bits/stdc++.h>
using namespace std;

long long int dp[50];

long long int fib(int n) {
    if(n == 0 || n == 1) return n;
    
    if(dp[n] != -1) return dp[n];
    
    dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    
    for(int i = 0; i <= n; i++) {
        dp[i] = -1;
    }
    
    cout << fib(n) << "\n";
    
    return 0;
}
```

## Alternative Solution (Bottom-up DP)

```cpp
#include<bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    
    if(n == 0) {
        cout << 0 << "\n";
        return 0;
    }
    
    if(n == 1) {
        cout << 1 << "\n";
        return 0;
    }
    
    long long int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    cout << dp[n] << "\n";
    
    return 0;
}
```

## Time Complexity: O(n)
## Space Complexity: O(n)

## Approach
Instead of naive recursion which takes O(2^n) time, we use dynamic programming with memoization to store previously calculated values. This reduces the time complexity to O(n).