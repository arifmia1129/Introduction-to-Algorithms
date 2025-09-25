# Quick Shot - All Important Topics Cheat Sheet

## 1. Arrays & Vectors
*Dynamic arrays that can grow/shrink during runtime*

### Basic Operations
```cpp
vector<int> v = {1, 2, 3, 4, 5};
v.push_back(6);           // Add element at end - O(1)
v.pop_back();             // Remove last element - O(1)  
cout << v[0];             // Access by index - O(1)
cout << v.size();         // Get size - O(1)
v.clear();                // Remove all elements
```

### Prefix Sum
*Precompute cumulative sums for fast range queries*
```cpp
vector<int> prefix(n + 1, 0);
for(int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + arr[i];
}
// Range sum [L, R] = prefix[R + 1] - prefix[L] in O(1)
```

### Suffix Sum
*Precompute sums from right to left*
```cpp
vector<int> suffix(n + 1, 0);
for(int i = n - 1; i >= 0; i--) {
    suffix[i] = suffix[i + 1] + arr[i];
}
```

---

## 2. Searching
*Finding elements in data structures*

### Linear Search - O(n)
*Check every element one by one*
```cpp
int linear_search(vector<int>& arr, int target) {
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == target) return i;    // Found at index i
    }
    return -1;                            // Not found
}
```

### Binary Search - O(log n)
*Search in sorted array by dividing search space in half*
```cpp
int binary_search(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;  // Avoid overflow
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) left = mid + 1;   // Search right half
        else right = mid - 1;                        // Search left half
    }
    return -1;
}
```

### STL Binary Search
```cpp
bool found = binary_search(arr.begin(), arr.end(), target);
int pos = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
```

---

## 3. Sorting

### Built-in Sort
```cpp
sort(arr.begin(), arr.end());                    // Ascending
sort(arr.begin(), arr.end(), greater<int>());    // Descending
```

### Custom Comparator
```cpp
bool cmp(pair<int,string> a, pair<int,string> b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
sort(students.begin(), students.end(), cmp);
```

---

## 4. Stack

### Basic Operations
```cpp
stack<int> st;
st.push(10);              // Push
st.pop();                 // Pop
cout << st.top();         // Top element
cout << st.empty();       // Check empty
```

### Valid Parentheses
```cpp
bool isValid(string s) {
    stack<char> st;
    for(char c : s) {
        if(c == '(' || c == '[' || c == '{') st.push(c);
        else {
            if(st.empty()) return false;
            char top = st.top(); st.pop();
            if((c == ')' && top != '(') || 
               (c == ']' && top != '[') || 
               (c == '}' && top != '{')) return false;
        }
    }
    return st.empty();
}
```

---

## 5. Queue

### Basic Operations
```cpp
queue<int> q;
q.push(10);               // Enqueue
q.pop();                  // Dequeue
cout << q.front();        // Front element
cout << q.empty();        // Check empty
```

### Priority Queue (Max Heap)
```cpp
priority_queue<int> pq;
pq.push(10);              // Insert
cout << pq.top();         // Max element
pq.pop();                 // Remove max
```

---

## 6. Linked List

### Node Definition
```cpp
class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};
```

### Insert at Head
```cpp
void insert_at_head(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}
```

### Print List
```cpp
void print_list(Node* head) {
    Node* tmp = head;
    while(tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}
```

---

## 7. Doubly Linked List

### Node Definition
```cpp
class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
```

### Insert at Tail
```cpp
void insert_at_tail(Node*& tail, int val) {
    Node* newNode = new Node(val);
    if(tail == NULL) {
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
```

---

## 8. Binary Tree

### Node Definition
```cpp
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
```

### Tree Traversals
```cpp
// Preorder
void preorder(Node* root) {
    if(root == NULL) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder
void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Postorder
void postorder(Node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
```

### Level Order Traversal
```cpp
void level_order(Node* root) {
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* f = q.front();
        q.pop();
        cout << f->val << " ";
        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
    }
}
```

---

## 9. Binary Search Tree (BST)

### Search in BST
```cpp
bool search(Node* root, int x) {
    if(root == NULL) return false;
    if(root->val == x) return true;
    if(x < root->val) return search(root->left, x);
    else return search(root->right, x);
}
```

### Insert in BST
```cpp
Node* insert(Node* root, int x) {
    if(root == NULL) return new Node(x);
    if(x < root->val) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}
```

---

## 10. Heap

### Max Heap Implementation
```cpp
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
            } else break;
            cur_idx = parent_idx;
        }
    }
    
    int get_max() {
        return heap.empty() ? -1 : heap[0];
    }
};
```

---

## 11. Graph Representation

### Adjacency List
```cpp
vector<vector<int>> adj(n);
for(int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);  // For undirected
}
```

### Adjacency Matrix
```cpp
int adj[n][n];
memset(adj, 0, sizeof(adj));
for(int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u][v] = 1;
    adj[v][u] = 1;  // For undirected
}
```

---

## 12. Graph Traversals

### DFS (Depth First Search)
```cpp
vector<bool> vis(n, false);

void dfs(int src) {
    vis[src] = true;
    cout << src << " ";
    for(int child : adj[src]) {
        if(!vis[child]) {
            dfs(child);
        }
    }
}
```

### BFS (Breadth First Search)
```cpp
vector<bool> vis(n, false);
vector<int> dis(n, -1);

void bfs(int src) {
    queue<int> q;
    q.push(src);
    vis[src] = true;
    dis[src] = 0;
    
    while(!q.empty()) {
        int par = q.front();
        q.pop();
        cout << par << " ";
        
        for(int child : adj[par]) {
            if(!vis[child]) {
                q.push(child);
                vis[child] = true;
                dis[child] = dis[par] + 1;
            }
        }
    }
}
```

---

## 13. BFS on 2D Grid

### 2D BFS
```cpp
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool valid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs_2d(vector<string>& grid, int n, int m) {
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    
    q.push({0, 0});
    vis[0][0] = true;
    
    while(!q.empty()) {
        pair<int, int> par = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int ci = par.first + dx[i];
            int cj = par.second + dy[i];
            
            if(valid(ci, cj, n, m) && !vis[ci][cj] && grid[ci][cj] == '.') {
                q.push({ci, cj});
                vis[ci][cj] = true;
            }
        }
    }
}
```

---

## 14. Shortest Path Algorithms

### Dijkstra's Algorithm
```cpp
vector<int> dijkstra(int src, int n) {
    vector<int> dis(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dis[src] = 0;
    pq.push({0, src});
    
    while(!pq.empty()) {
        pair<int, int> parent = pq.top();
        pq.pop();
        
        int node = parent.second;
        int cost = parent.first;
        
        if(cost > dis[node]) continue;
        
        for(pair<int, int> child : adj[node]) {
            int childNode = child.first;
            int childCost = child.second;
            
            if(dis[node] + childCost < dis[childNode]) {
                dis[childNode] = dis[node] + childCost;
                pq.push({dis[childNode], childNode});
            }
        }
    }
    
    return dis;
}
```

---

## 15. Recursion

### Basic Recursion
```cpp
int factorial(int n) {
    if(n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

void print_n_to_1(int n) {
    if(n == 0) return;
    cout << n << " ";
    print_n_to_1(n - 1);
}
```

### Fibonacci
```cpp
int fib(int n) {
    if(n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}
```

---

## 16. Dynamic Programming

### Fibonacci with Memoization
```cpp
int dp[50];
int fib_memo(int n) {
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fib_memo(n - 1) + fib_memo(n - 2);
}
```

### 0/1 Knapsack
```cpp
int knapsack(int i, int w, vector<int>& weight, vector<int>& value) {
    if(i == n || w == 0) return 0;
    if(dp[i][w] != -1) return dp[i][w];
    
    int ans = knapsack(i + 1, w, weight, value);
    if(weight[i] <= w) {
        ans = max(ans, knapsack(i + 1, w - weight[i], weight, value) + value[i]);
    }
    
    return dp[i][w] = ans;
}
```

---

## 17. STL Containers

### Set (Ordered, Unique)
```cpp
set<int> s;
s.insert(10);
s.erase(10);
cout << s.count(10);      // 0 or 1
```

### Map (Key-Value)
```cpp
map<string, int> mp;
mp["alice"] = 85;
cout << mp["alice"];
```

### Pair
```cpp
pair<int, string> p = {85, "Alice"};
cout << p.first << " " << p.second;
```

---

## 18. Time Complexity Quick Reference

- **O(1)**: Array access, stack/queue operations
- **O(log n)**: Binary search, heap operations
- **O(n)**: Linear search, array traversal
- **O(n log n)**: Merge sort, quick sort, dijkstra
- **O(n²)**: Bubble sort, nested loops
- **O(2^n)**: Recursive fibonacci (without memoization)

---

## 19. Common Patterns

### Two Pointers
```cpp
int left = 0, right = arr.size() - 1;
while(left < right) {
    if(arr[left] + arr[right] == target) {
        // Found pair
        left++; right--;
    } else if(arr[left] + arr[right] < target) {
        left++;
    } else {
        right--;
    }
}
```

### Sliding Window
```cpp
int left = 0, right = 0, maxLen = 0;
while(right < n) {
    // Expand window
    windowSum += arr[right];
    
    // Contract window if needed
    while(windowSum > target) {
        windowSum -= arr[left];
        left++;
    }
    
    maxLen = max(maxLen, right - left + 1);
    right++;
}
```

---

## 20. Fast I/O Template

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Your code here
    
    return 0;
}
```