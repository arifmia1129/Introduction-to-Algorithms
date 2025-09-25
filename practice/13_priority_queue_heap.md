# Question 13: Priority Queue Operations (Max Heap)

## Problem Statement
Implement a max heap using priority queue with the following operations:
1. Insert an element
2. Extract maximum element
3. Get current maximum without removing
4. Get current size

## Input Format
- First line contains q, number of operations
- Next q lines contain operations:
  - 1 X: Insert X
  - 2: Extract maximum (print it, then remove)
  - 3: Print current maximum (don't remove)
  - 4: Print current size

## Constraints
- 1 ≤ q ≤ 10⁵
- 1 ≤ X ≤ 10⁶

## Output Format
For operations 2, 3, and 4, print the result. If heap is empty, print -1

## Sample Input 0
```
8
1 10
1 20
3
1 5
2
3
4
2
```

## Sample Output 0
```
20
20
10
2
10
```

## Solution

```cpp
#include<bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int> pq;
    
    int q; cin >> q;
    
    while(q--) {
        int op; cin >> op;
        
        if(op == 1) {
            int x; cin >> x;
            pq.push(x);
        } else if(op == 2) {
            if(pq.empty()) {
                cout << -1 << "\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else if(op == 3) {
            if(pq.empty()) {
                cout << -1 << "\n";
            } else {
                cout << pq.top() << "\n";
            }
        } else if(op == 4) {
            cout << pq.size() << "\n";
        }
    }
    
    return 0;
}
```

## Custom Heap Implementation Solution

```cpp
#include<bits/stdc++.h>
using namespace std;

class MaxHeap {
public:
    vector<int> heap;
    
    void insert(int val) {
        heap.push_back(val);
        
        int cur_idx = heap.size() - 1;
        
        while(cur_idx != 0) {
            int parent_idx = (cur_idx - 1) / 2;
            if(heap[parent_idx] < heap[cur_idx]) {
                swap(heap[parent_idx], heap[cur_idx]);
            } else {
                break;
            }
            cur_idx = parent_idx;
        }
    }
    
    void delete_heap() {
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        
        int cur_idx = 0;
        while(true) {
            int left_idx = cur_idx * 2 + 1;
            int right_idx = cur_idx * 2 + 2;
            int last_idx = heap.size() - 1;
            
            if(left_idx <= last_idx && right_idx <= last_idx) {
                if(heap[left_idx] >= heap[right_idx] && heap[left_idx] > heap[cur_idx]) {
                    swap(heap[left_idx], heap[cur_idx]);
                    cur_idx = left_idx;
                } else if(heap[right_idx] >= heap[left_idx] && heap[right_idx] > heap[cur_idx]) {
                    swap(heap[right_idx], heap[cur_idx]);
                    cur_idx = right_idx;
                } else {
                    break;
                }
            } else if(left_idx <= last_idx) {
                if(heap[left_idx] > heap[cur_idx]) {
                    swap(heap[left_idx], heap[cur_idx]);
                    cur_idx = left_idx;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }
    
    int get_max() {
        if(heap.empty()) return -1;
        return heap[0];
    }
    
    int extract_max() {
        if(heap.empty()) return -1;
        int max_val = heap[0];
        delete_heap();
        return max_val;
    }
    
    int size() {
        return heap.size();
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    MaxHeap mh;
    
    int q; cin >> q;
    
    while(q--) {
        int op; cin >> op;
        
        if(op == 1) {
            int x; cin >> x;
            mh.insert(x);
        } else if(op == 2) {
            cout << mh.extract_max() << "\n";
        } else if(op == 3) {
            cout << mh.get_max() << "\n";
        } else if(op == 4) {
            cout << mh.size() << "\n";
        }
    }
    
    return 0;
}
```

## Time Complexity: O(log n) for insert and extract, O(1) for top and size
## Space Complexity: O(n)

## Approach
We use STL priority_queue which implements max heap by default. For custom implementation, we maintain the heap property: parent >= children, using up-heapify for insertion and down-heapify for deletion.