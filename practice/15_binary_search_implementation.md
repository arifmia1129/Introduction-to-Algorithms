# Question 15: Binary Search Implementation

## Problem Statement
You are given a sorted array and multiple search queries. For each query, determine if the target element exists in the array and return its index (0-based). If not found, return -1.

## Input Format
- First line contains n, size of array
- Second line contains n sorted integers
- Third line contains q, number of queries
- Next q lines contain target values to search

## Constraints
- 1 ≤ n ≤ 10⁵
- 1 ≤ q ≤ 10⁵
- 1 ≤ array elements ≤ 10⁶
- 1 ≤ target ≤ 10⁶

## Output Format
For each query, print the index if found, otherwise -1

## Sample Input 0
```
5
1 3 5 7 9
3
5
2
7
```

## Sample Output 0
```
2
-1
3
```

## Solution

```cpp
#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        if(arr[mid] == target) {
            return mid;
        } else if(arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int q; cin >> q;
    
    while(q--) {
        int target; cin >> target;
        
        int result = binary_search(arr, target);
        cout << result << "\n";
    }
    
    return 0;
}
```

## Time Complexity: O(log n) per query
## Space Complexity: O(1)

## Approach
Binary search works on sorted arrays by repeatedly dividing the search space in half. We compare the target with the middle element and eliminate half of the remaining elements based on the comparison.