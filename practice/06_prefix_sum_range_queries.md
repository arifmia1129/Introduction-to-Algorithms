# Question 6: Prefix Sum Range Queries

## Problem Statement
You are given an array of integers and multiple range sum queries. For each query, you need to find the sum of elements from index L to R (inclusive, 0-indexed).

## Input Format
- First line contains n, the size of array
- Second line contains n space-separated integers
- Third line contains q, number of queries
- Next q lines contain L and R for each query

## Constraints
- 1 ≤ n ≤ 10⁵
- 1 ≤ q ≤ 10⁵
- -10³ ≤ arr[i] ≤ 10³
- 0 ≤ L ≤ R < n

## Output Format
For each query, print the sum of elements from L to R

## Sample Input 0
```
5
1 3 5 7 9
3
0 2
1 4
2 2
```

## Sample Output 0
```
9
24
5
```

## Solution

```cpp
#include<bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    
    vector<long long int> arr(n);
    vector<long long int> prefix(n + 1, 0);
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        prefix[i + 1] = prefix[i] + arr[i];
    }
    
    int q; cin >> q;
    
    while(q--) {
        int l, r; cin >> l >> r;
        
        long long int sum = prefix[r + 1] - prefix[l];
        cout << sum << "\n";
    }
    
    return 0;
}
```

## Time Complexity: O(n + q)
## Space Complexity: O(n)

## Approach
We use prefix sum technique to answer range sum queries efficiently. We precompute prefix sums where prefix[i] = sum of elements from index 0 to i-1. For any range [L, R], the sum is prefix[R+1] - prefix[L].