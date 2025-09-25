# Question 8: Queue Operations

## Problem Statement
You have an empty queue initially. You will be given q queries to perform on this queue. There are 3 types of queries:

1. 1 X - enqueue element X to the back of the queue
2. 2 - dequeue element from front of the queue (if queue is not empty)
3. 3 - print the front element of the queue (if queue is not empty), otherwise print -1

## Input Format
- First line contains q, number of queries
- Next q lines contain queries

## Constraints
- 1 ≤ q ≤ 10⁵
- 1 ≤ X ≤ 10⁹

## Output Format
For each type 3 query, print the front element or -1

## Sample Input 0
```
8
1 10
1 20
3
2
3
1 30
3
2
```

## Sample Output 0
```
10
20
30
```

## Solution

```cpp
#include<bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;
    
    queue<int> que;
    
    while(q--) {
        int type; cin >> type;
        
        if(type == 1) {
            int x; cin >> x;
            que.push(x);
        } else if(type == 2) {
            if(!que.empty()) {
                que.pop();
            }
        } else if(type == 3) {
            if(!que.empty()) {
                cout << que.front() << "\n";
            } else {
                cout << -1 << "\n";
            }
        }
    }
    
    return 0;
}
```

## Time Complexity: O(q)
## Space Complexity: O(n) where n is maximum queue size

## Approach
We use the STL queue to implement FIFO (First In First Out) operations. For each query type, we perform the corresponding queue operation while checking if the queue is empty for dequeue and front operations.