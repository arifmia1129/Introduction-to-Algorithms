# Question 9: Linked List Cycle Detection

## Problem Statement
You are given a representation of a linked list. Each node has a value and points to the next node. Some nodes might point to a previous node, creating a cycle. Detect if there is a cycle in the linked list.

You are given n nodes and their connections. Node i points to node connections[i]. If connections[i] is -1, it means node i doesn't point to any node.

## Input Format
- First line contains n, number of nodes
- Second line contains n space-separated integers representing connections

## Constraints
- 1 ≤ n ≤ 10⁵
- -1 ≤ connections[i] ≤ n-1

## Output Format
Print "YES" if cycle exists, "NO" otherwise

## Sample Input 0
```
4
1 2 3 -1
```

## Sample Output 0
```
NO
```

## Sample Input 1
```
4
1 2 0 1
```

## Sample Output 1
```
YES
```

## Solution

```cpp
#include<bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    
    vector<int> connections(n);
    for(int i = 0; i < n; i++) {
        cin >> connections[i];
    }
    
    // Floyd's Cycle Detection Algorithm (Tortoise and Hare)
    for(int start = 0; start < n; start++) {
        if(connections[start] == -1) continue;
        
        int slow = start;
        int fast = start;
        
        while(connections[fast] != -1 && connections[connections[fast]] != -1) {
            slow = connections[slow];
            fast = connections[connections[fast]];
            
            if(slow == fast) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    
    cout << "NO\n";
    
    return 0;
}
```

## Time Complexity: O(n)
## Space Complexity: O(1)

## Approach
We use Floyd's Cycle Detection Algorithm (Tortoise and Hare method). We have two pointers: slow moves one step at a time, fast moves two steps. If there's a cycle, they will eventually meet. We check for each possible starting node to handle disconnected components.