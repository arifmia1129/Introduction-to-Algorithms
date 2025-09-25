# Question 20: Time Complexity Analysis Challenge

## Problem Statement
Given different algorithms, analyze and implement the most efficient solution for finding all pairs in an array whose sum equals a target value.

## Input Format
- First line contains n, size of array
- Second line contains n integers
- Third line contains target sum

## Constraints
- 1 ≤ n ≤ 10⁵
- -10⁶ ≤ array elements ≤ 10⁶
- -10⁶ ≤ target ≤ 10⁶

## Output Format
Print all pairs (i,j) where arr[i] + arr[j] = target and i < j. If no pairs found, print "No pairs found"

## Sample Input 0
```
6
1 2 3 4 5 6
7
```

## Sample Output 0
```
(1,5)
(2,4)
```

## Solution 1: Naive Approach O(n²)

```cpp
#include<bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int target; cin >> target;
    
    vector<pair<int, int>> pairs;
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == target) {
                pairs.push_back({arr[i], arr[j]});
            }
        }
    }
    
    if(pairs.empty()) {
        cout << "No pairs found\n";
    } else {
        for(auto p : pairs) {
            cout << "(" << p.first << "," << p.second << ")\n";
        }
    }
    
    return 0;
}
```

## Solution 2: Optimized Approach O(n) using Hash Map

```cpp
#include<bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int target; cin >> target;
    
    unordered_map<int, vector<int>> mp;
    vector<pair<int, int>> pairs;
    
    for(int i = 0; i < n; i++) {
        int complement = target - arr[i];
        
        if(mp.count(complement)) {
            for(int idx : mp[complement]) {
                if(idx < i) {
                    pairs.push_back({arr[idx], arr[i]});
                }
            }
        }
        
        mp[arr[i]].push_back(i);
    }
    
    if(pairs.empty()) {
        cout << "No pairs found\n";
    } else {
        for(auto p : pairs) {
            cout << "(" << p.first << "," << p.second << ")\n";
        }
    }
    
    return 0;
}
```

## Solution 3: Two Pointer Approach O(n log n) - Requires Sorting

```cpp
#include<bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        arr[i] = {x, i};
    }
    
    int target; cin >> target;
    
    sort(arr.begin(), arr.end());
    
    vector<pair<int, int>> pairs;
    
    int left = 0, right = n - 1;
    
    while(left < right) {
        int sum = arr[left].first + arr[right].first;
        
        if(sum == target) {
            int i = min(arr[left].second, arr[right].second);
            int j = max(arr[left].second, arr[right].second);
            pairs.push_back({arr[left].first, arr[right].first});
            left++;
            right--;
        } else if(sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    if(pairs.empty()) {
        cout << "No pairs found\n";
    } else {
        for(auto p : pairs) {
            cout << "(" << p.first << "," << p.second << ")\n";
        }
    }
    
    return 0;
}
```

## Time Complexity Comparison:
- Solution 1: O(n²) - Check all pairs
- Solution 2: O(n) - Hash map lookup  
- Solution 3: O(n log n) - Sorting + Two pointers

## Space Complexity:
- Solution 1: O(1) extra space
- Solution 2: O(n) for hash map
- Solution 3: O(n) for sorted pairs

## Approach
Three different approaches showing complexity trade-offs:
1. Brute force checking all pairs
2. Hash map for O(1) complement lookup 
3. Two pointers after sorting for space efficiency