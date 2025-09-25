# Question 3: Frog Olympics - Solution

## Solution

```cpp
#include<bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        
        bool leapy = false, jumpster = false;
        
        // Check if Leapy can reach (jumps 3 or 4)
        // Using DP approach to check reachability
        vector<bool> dp_leapy(n + 1, false);
        dp_leapy[0] = true;
        
        for(int i = 0; i <= n; i++) {
            if(dp_leapy[i]) {
                if(i + 3 <= n) dp_leapy[i + 3] = true;
                if(i + 4 <= n) dp_leapy[i + 4] = true;
            }
        }
        leapy = dp_leapy[n];
        
        // Check if Jumpster can reach (jumps 3 or 5)
        vector<bool> dp_jumpster(n + 1, false);
        dp_jumpster[0] = true;
        
        for(int i = 0; i <= n; i++) {
            if(dp_jumpster[i]) {
                if(i + 3 <= n) dp_jumpster[i + 3] = true;
                if(i + 5 <= n) dp_jumpster[i + 5] = true;
            }
        }
        jumpster = dp_jumpster[n];
        
        if(leapy && jumpster) {
            cout << "Both\n";
        } else if(leapy) {
            cout << "Leapy\n";
        } else if(jumpster) {
            cout << "Jumpster\n";
        } else {
            cout << "None\n";
        }
    }
    
    return 0;
}
```

## Time Complexity: O(t × n)
## Space Complexity: O(n)

## Approach
This problem can be solved using dynamic programming. For each frog, we check if it's possible to reach stone n from stone 0. We use a DP array where dp[i] represents whether we can reach stone i. We iterate through all positions and if we can reach position i, we mark positions i+3 and i+4 (for Leapy) or i+3 and i+5 (for Jumpster) as reachable.