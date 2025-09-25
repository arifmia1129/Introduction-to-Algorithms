# Quick Shot - Comprehensive DSA Cheat Sheet

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
v.resize(10);             // Change size to 10
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

### 2D Arrays
```cpp
vector<vector<int>> grid(n, vector<int>(m, 0));  // n×m grid
grid[i][j] = value;                               // Access element
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
int pos2 = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
```

---

## 3. Sorting
*Arranging elements in order*

### Built-in Sort - O(n log n)
```cpp
sort(arr.begin(), arr.end());                    // Ascending
sort(arr.begin(), arr.end(), greater<int>());    // Descending
reverse(arr.begin(), arr.end());                 // Reverse array
```

### Custom Comparator
*Sort with custom rules*
```cpp
bool cmp(pair<int,string> a, pair<int,string> b) {
    if(a.first == b.first) return a.second < b.second;  // Tie-breaker
    return a.first > b.first;                            // Primary sort
}
sort(students.begin(), students.end(), cmp);
```

### Counting Sort - O(n + k)
*When elements are in small range*
```cpp
void counting_sort(vector<int>& arr, int max_val) {
    vector<int> count(max_val + 1, 0);
    for(int x : arr) count[x]++;
    
    int idx = 0;
    for(int i = 0; i <= max_val; i++) {
        for(int j = 0; j < count[i]; j++) {
            arr[idx++] = i;
        }
    }
}
```

---

## 4. Stack (LIFO - Last In First Out)
*Stores elements in reverse order of insertion*

### Basic Operations
```cpp
stack<int> st;
st.push(10);              // Push element - O(1)
st.pop();                 // Pop top element - O(1)
cout << st.top();         // Get top element - O(1)
cout << st.empty();       // Check if empty - O(1)
cout << st.size();        // Get size - O(1)
```

### Valid Parentheses
*Classic stack application*
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

### Stack using Array
```cpp
class Stack {
    int arr[1000], top_idx;
public:
    Stack() { top_idx = -1; }
    void push(int x) { arr[++top_idx] = x; }
    void pop() { top_idx--; }
    int top() { return arr[top_idx]; }
    bool empty() { return top_idx == -1; }
};
```

---

## 5. Queue (FIFO - First In First Out)
*Serves elements in order of insertion*

### Basic Operations
```cpp
queue<int> q;
q.push(10);               // Enqueue - O(1)
q.pop();                  // Dequeue - O(1)
cout << q.front();        // Front element - O(1)
cout << q.back();         // Back element - O(1)
cout << q.empty();        // Check if empty - O(1)
cout << q.size();         // Get size - O(1)
```

### Priority Queue (Max Heap by default)
*Elements served by priority, not insertion order*
```cpp
priority_queue<int> pq;                    // Max heap
pq.push(10);                              // Insert - O(log n)
cout << pq.top();                         // Max element - O(1)
pq.pop();                                 // Remove max - O(log n)

priority_queue<int, vector<int>, greater<int>> min_pq;  // Min heap
```

### Queue using Array
```cpp
class Queue {
    int arr[1000], front_idx, rear_idx;
public:
    Queue() { front_idx = 0; rear_idx = -1; }
    void push(int x) { arr[++rear_idx] = x; }
    void pop() { front_idx++; }
    int front() { return arr[front_idx]; }
    bool empty() { return front_idx > rear_idx; }
};
```

---

## 6. Linked List
*Nodes connected via pointers, dynamic size*

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

### Basic Operations
```cpp
// Insert at Head - O(1)
void insert_at_head(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Insert at Tail - O(n) without tail pointer
void insert_at_tail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    Node* tmp = head;
    while(tmp->next != NULL) tmp = tmp->next;
    tmp->next = newNode;
}

// Delete by value - O(n)
void delete_node(Node*& head, int val) {
    if(head == NULL) return;
    if(head->val == val) {
        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;
        return;
    }
    Node* tmp = head;
    while(tmp->next != NULL && tmp->next->val != val) {
        tmp = tmp->next;
    }
    if(tmp->next != NULL) {
        Node* deleteNode = tmp->next;
        tmp->next = tmp->next->next;
        delete deleteNode;
    }
}
```

### Print & Traverse
```cpp
void print_list(Node* head) {
    Node* tmp = head;
    while(tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}

int get_size(Node* head) {
    int count = 0;
    Node* tmp = head;
    while(tmp != NULL) {
        count++;
        tmp = tmp->next;
    }
    return count;
}
```

### Reverse Linked List
```cpp
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;  // New head
}
```

---

## 7. Doubly Linked List
*Each node has pointers to both next and previous nodes*

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

### Basic Operations
```cpp
// Insert at Head - O(1)
void insert_at_head(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if(head == NULL) {
        head = tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Insert at Tail - O(1)
void insert_at_tail(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if(tail == NULL) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// Print Forward & Backward
void print_forward(Node* head) {
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
}

void print_backward(Node* tail) {
    while(tail != NULL) {
        cout << tail->val << " ";
        tail = tail->prev;
    }
}
```

---

## 8. Binary Tree
*Hierarchical structure where each node has at most 2 children*

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
// Preorder: Root -> Left -> Right
void preorder(Node* root) {
    if(root == NULL) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder: Left -> Root -> Right (gives sorted order in BST)
void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Postorder: Left -> Right -> Root
void postorder(Node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
```

### Level Order Traversal (BFS)
*Visit nodes level by level using queue*
```cpp
void level_order(Node* root) {
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        int level_size = q.size();
        for(int i = 0; i < level_size; i++) {
            Node* node = q.front();
            q.pop();
            cout << node->val << " ";
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        cout << "\n";  // New line after each level
    }
}
```

### Tree Properties
```cpp
// Count total nodes
int count_nodes(Node* root) {
    if(root == NULL) return 0;
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

// Count leaf nodes
int count_leaf(Node* root) {
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    return count_leaf(root->left) + count_leaf(root->right);
}

// Calculate height/depth
int height(Node* root) {
    if(root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}
```

---

## 9. Binary Search Tree (BST)
*Binary tree where left subtree < root < right subtree*

### Basic Operations
```cpp
// Search in BST - O(log n) average, O(n) worst
bool search(Node* root, int x) {
    if(root == NULL) return false;
    if(root->val == x) return true;
    if(x < root->val) return search(root->left, x);
    else return search(root->right, x);
}

// Insert in BST - O(log n) average
Node* insert(Node* root, int x) {
    if(root == NULL) return new Node(x);
    if(x < root->val) root->left = insert(root->left, x);
    else if(x > root->val) root->right = insert(root->right, x);
    return root;  // Duplicate values ignored
}

// Find minimum value
Node* find_min(Node* root) {
    while(root && root->left) root = root->left;
    return root;
}

// Delete node from BST
Node* delete_node(Node* root, int x) {
    if(root == NULL) return root;
    
    if(x < root->val) root->left = delete_node(root->left, x);
    else if(x > root->val) root->right = delete_node(root->right, x);
    else {
        if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        Node* temp = find_min(root->right);
        root->val = temp->val;
        root->right = delete_node(root->right, temp->val);
    }
    return root;
}
```

---

## 10. Heap (Priority Queue Implementation)
*Complete binary tree with heap property*

### Max Heap Implementation
```cpp
class MaxHeap {
public:
    vector<int> heap;
    
    // Insert element - O(log n)
    void insert(int val) {
        heap.push_back(val);
        int cur_idx = heap.size() - 1;
        
        // Up-heapify
        while(cur_idx != 0) {
            int parent_idx = (cur_idx - 1) / 2;
            if(heap[parent_idx] < heap[cur_idx]) {
                swap(heap[parent_idx], heap[cur_idx]);
            } else break;
            cur_idx = parent_idx;
        }
    }
    
    // Extract maximum - O(log n)
    void extract_max() {
        if(heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        
        // Down-heapify
        int cur_idx = 0;
        while(true) {
            int left_idx = cur_idx * 2 + 1;
            int right_idx = cur_idx * 2 + 2;
            int largest = cur_idx;
            
            if(left_idx < heap.size() && heap[left_idx] > heap[largest])
                largest = left_idx;
            if(right_idx < heap.size() && heap[right_idx] > heap[largest])
                largest = right_idx;
                
            if(largest != cur_idx) {
                swap(heap[cur_idx], heap[largest]);
                cur_idx = largest;
            } else break;
        }
    }
    
    int get_max() { return heap.empty() ? -1 : heap[0]; }
    bool empty() { return heap.empty(); }
};
```

---

## 11. Graph Representation
*Collection of vertices connected by edges*

### Adjacency List (Space efficient)
```cpp
vector<vector<int>> adj(n);  // For n vertices
// Add edge u -> v
adj[u].push_back(v);
adj[v].push_back(u);  // For undirected graph

// Weighted graph
vector<vector<pair<int, int>>> adj(n);
adj[u].push_back({v, weight});
```

### Adjacency Matrix (Fast lookup)
```cpp
vector<vector<int>> adj(n, vector<int>(n, 0));
// Add edge u -> v
adj[u][v] = 1;
adj[v][u] = 1;  // For undirected graph

// Weighted graph: store weight instead of 1
adj[u][v] = weight;
```

### Edge List
```cpp
vector<pair<int, int>> edges;  // For unweighted
vector<tuple<int, int, int>> edges;  // For weighted: {u, v, weight}
```

---

## 12. Graph Traversals
*Systematic way to visit all vertices*

### DFS (Depth First Search) - O(V + E)
*Go deep as possible before backtracking*
```cpp
vector<bool> vis(n, false);

void dfs(int src, vector<vector<int>>& adj) {
    vis[src] = true;
    cout << src << " ";
    
    for(int child : adj[src]) {
        if(!vis[child]) {
            dfs(child, adj);
        }
    }
}

// Count connected components
int count_components(int n, vector<vector<int>>& adj) {
    vector<bool> vis(n, false);
    int components = 0;
    
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, adj);
            components++;
        }
    }
    return components;
}
```

### BFS (Breadth First Search) - O(V + E)
*Visit all neighbors before going to next level*
```cpp
void bfs(int src, vector<vector<int>>& adj) {
    vector<bool> vis(n, false);
    vector<int> dis(n, -1);
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
                dis[child] = dis[par] + 1;  // Distance from source
            }
        }
    }
}
```

### Cycle Detection
```cpp
// Using DFS for undirected graph
bool has_cycle_dfs(int src, int parent, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[src] = true;
    
    for(int child : adj[src]) {
        if(!vis[child]) {
            if(has_cycle_dfs(child, src, adj, vis)) return true;
        } else if(child != parent) {
            return true;  // Back edge found
        }
    }
    return false;
}
```

---

## 13. BFS on 2D Grid
*Treating 2D grid as a graph*

### 4-Directional Movement
```cpp
int dx[4] = {-1, 0, 1, 0};  // Up, Right, Down, Left
int dy[4] = {0, 1, 0, -1};

bool valid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

// Find shortest path from (0,0) to (n-1,m-1)
int bfs_2d(vector<string>& grid, int n, int m) {
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> dis(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    
    q.push({0, 0});
    vis[0][0] = true;
    dis[0][0] = 0;
    
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(valid(nx, ny, n, m) && !vis[nx][ny] && grid[nx][ny] == '.') {
                q.push({nx, ny});
                vis[nx][ny] = true;
                dis[nx][ny] = dis[x][y] + 1;
            }
        }
    }
    
    return dis[n-1][m-1];
}
```

### 8-Directional Movement
```cpp
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
```

---

## 14. Shortest Path Algorithms
*Finding minimum cost paths in weighted graphs*

### Dijkstra's Algorithm - O((V + E) log V)
*Single source shortest path for non-negative weights*
```cpp
const int INF = 1e9;

vector<int> dijkstra(int src, int n, vector<vector<pair<int, int>>>& adj) {
    vector<int> dis(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dis[src] = 0;
    pq.push({0, src});  // {distance, vertex}
    
    while(!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();
        
        if(cost > dis[u]) continue;  // Already processed
        
        for(auto [v, w] : adj[u]) {
            if(dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
    
    return dis;
}
```

### Bellman-Ford Algorithm - O(VE)
*Handles negative weights, detects negative cycles*
```cpp
bool bellman_ford(int src, int n, vector<tuple<int, int, int>>& edges) {
    vector<int> dis(n, INF);
    dis[src] = 0;
    
    // Relax edges n-1 times
    for(int i = 0; i < n - 1; i++) {
        for(auto [u, v, w] : edges) {
            if(dis[u] != INF && dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
            }
        }
    }
    
    // Check for negative cycle
    for(auto [u, v, w] : edges) {
        if(dis[u] != INF && dis[u] + w < dis[v]) {
            return false;  // Negative cycle exists
        }
    }
    return true;
}
```

### Floyd-Warshall - O(V³)
*All pairs shortest path*
```cpp
void floyd_warshall(vector<vector<int>>& dis, int n) {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dis[i][k] != INF && dis[k][j] != INF) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }
}
```

---

## 15. Recursion
*Function calling itself with smaller subproblems*

### Basic Examples
```cpp
// Factorial - O(n)
int factorial(int n) {
    if(n == 0 || n == 1) return 1;  // Base case
    return n * factorial(n - 1);    // Recursive case
}

// Fibonacci - O(2^n) without memoization
int fib(int n) {
    if(n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

// Power function - O(log n)
long long power(int base, int exp) {
    if(exp == 0) return 1;
    if(exp % 2 == 0) {
        long long half = power(base, exp / 2);
        return half * half;
    }
    return base * power(base, exp - 1);
}
```

### Array Operations with Recursion
```cpp
// Print array
void print_array(int arr[], int n, int i = 0) {
    if(i == n) return;
    cout << arr[i] << " ";
    print_array(arr, n, i + 1);
}

// Find sum
int array_sum(int arr[], int n) {
    if(n == 0) return 0;
    return arr[n - 1] + array_sum(arr, n - 1);
}

// Check if sorted
bool is_sorted(int arr[], int n) {
    if(n <= 1) return true;
    return (arr[n - 1] >= arr[n - 2]) && is_sorted(arr, n - 1);
}
```

---

## 16. Dynamic Programming
*Optimize recursion by storing subproblem results*

### Memoization (Top-Down)
```cpp
int dp[50];
memset(dp, -1, sizeof(dp));

int fib_memo(int n) {
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];  // Already computed
    return dp[n] = fib_memo(n - 1) + fib_memo(n - 2);
}
```

### Tabulation (Bottom-Up)
```cpp
int fib_tab(int n) {
    if(n <= 1) return n;
    int dp[n + 1];
    dp[0] = 0; dp[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
```

### 0/1 Knapsack Problem
```cpp
int dp[105][1005];

// Top-down approach
int knapsack(int i, int w, vector<int>& weight, vector<int>& value, int n) {
    if(i == n || w == 0) return 0;
    if(dp[i][w] != -1) return dp[i][w];
    
    int ans = knapsack(i + 1, w, weight, value, n);  // Don't take
    if(weight[i] <= w) {
        ans = max(ans, knapsack(i + 1, w - weight[i], weight, value, n) + value[i]);
    }
    
    return dp[i][w] = ans;
}
```

### Longest Common Subsequence (LCS)
```cpp
int lcs(string a, string b, int i, int j) {
    if(i == a.length() || j == b.length()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    if(a[i] == b[j]) {
        return dp[i][j] = 1 + lcs(a, b, i + 1, j + 1);
    } else {
        return dp[i][j] = max(lcs(a, b, i + 1, j), lcs(a, b, i, j + 1));
    }
}
```

---

## 17. STL Containers
*Standard Template Library data structures*

### Set (Ordered, Unique elements)
```cpp
set<int> s;
s.insert(10);             // O(log n)
s.erase(10);              // O(log n)
cout << s.count(10);      // 0 or 1
cout << s.size();         // Number of elements

auto it = s.find(10);     // Iterator to element
if(it != s.end()) {       // Element found
    cout << *it;
}
```

### Multiset (Ordered, Allows duplicates)
```cpp
multiset<int> ms;
ms.insert(10);
ms.insert(10);           // Duplicates allowed
ms.erase(ms.find(10));   // Erase only one occurrence
ms.erase(10);            // Erase all occurrences
```

### Map (Key-Value pairs, Ordered by key)
```cpp
map<string, int> mp;
mp["alice"] = 85;
mp["bob"] = 90;
cout << mp["alice"];     // Access by key

for(auto [key, value] : mp) {
    cout << key << ": " << value << "\n";
}
```

### Unordered containers (Hash-based, O(1) average)
```cpp
unordered_set<int> us;
unordered_map<string, int> um;
```

### Pair and Vector of Pairs
```cpp
pair<int, string> p = {85, "Alice"};
cout << p.first << " " << p.second;

vector<pair<int, string>> students;
students.push_back({90, "Bob"});
sort(students.begin(), students.end());  // Sort by first element
```

---

## 18. String Algorithms
*Processing and manipulating strings*

### String Operations
```cpp
string s = "hello";
s += " world";           // Concatenation
cout << s.length();      // Size
cout << s.substr(1, 3);  // Substring from index 1, length 3
s.erase(1, 2);          // Erase 2 characters from index 1
s.replace(1, 2, "xyz"); // Replace 2 chars from index 1 with "xyz"
```

### String Searching
```cpp
string text = "hello world";
string pattern = "world";

size_t pos = text.find(pattern);
if(pos != string::npos) {
    cout << "Found at position " << pos;
}
```

### Character Classification
```cpp
char c = 'A';
if(isalpha(c)) cout << "Letter";
if(isdigit(c)) cout << "Digit";
if(islower(c)) cout << "Lowercase";
if(isupper(c)) cout << "Uppercase";

c = tolower(c);  // Convert to lowercase
c = toupper(c);  // Convert to uppercase
```

---

## 19. Two Pointers & Sliding Window
*Efficient techniques for array/string problems*

### Two Pointers Technique
```cpp
// Find pair with given sum in sorted array
bool has_pair_sum(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while(left < right) {
        int sum = arr[left] + arr[right];
        if(sum == target) return true;
        else if(sum < target) left++;
        else right--;
    }
    return false;
}

// Remove duplicates from sorted array
int remove_duplicates(vector<int>& arr) {
    if(arr.empty()) return 0;
    
    int slow = 0;
    for(int fast = 1; fast < arr.size(); fast++) {
        if(arr[fast] != arr[slow]) {
            arr[++slow] = arr[fast];
        }
    }
    return slow + 1;  // New length
}
```

### Sliding Window Technique
```cpp
// Maximum sum of k consecutive elements
int max_sum_k_elements(vector<int>& arr, int k) {
    if(arr.size() < k) return -1;
    
    int window_sum = 0;
    for(int i = 0; i < k; i++) {
        window_sum += arr[i];
    }
    
    int max_sum = window_sum;
    for(int i = k; i < arr.size(); i++) {
        window_sum = window_sum - arr[i - k] + arr[i];  // Slide window
        max_sum = max(max_sum, window_sum);
    }
    
    return max_sum;
}
```

---

## 20. Time & Space Complexity
*Analyzing algorithm efficiency*

### Time Complexity Classes
```cpp
// O(1) - Constant time
int get_first(vector<int>& arr) {
    return arr[0];  // Always same time regardless of size
}

// O(log n) - Logarithmic time
int binary_search(vector<int>& arr, int target) {
    // Divides problem in half each time
}

// O(n) - Linear time
int find_max(vector<int>& arr) {
    int max_val = arr[0];
    for(int x : arr) {  // Single loop through n elements
        max_val = max(max_val, x);
    }
    return max_val;
}

// O(n log n) - Linearithmic time
void merge_sort(vector<int>& arr) {
    sort(arr.begin(), arr.end());  // Most efficient comparison sorts
}

// O(n²) - Quadratic time
void bubble_sort(vector<int>& arr) {
    for(int i = 0; i < n; i++) {      // Nested loops
        for(int j = 0; j < n - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// O(2^n) - Exponential time
int fibonacci_naive(int n) {
    if(n <= 1) return n;
    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);  // Recursive calls double
}
```

### Space Complexity
```cpp
// O(1) - Constant space
void swap_elements(int& a, int& b) {
    int temp = a;  // Only uses fixed amount of extra space
    a = b;
    b = temp;
}

// O(n) - Linear space
vector<int> create_copy(vector<int>& arr) {
    vector<int> copy(arr);  // Space proportional to input size
    return copy;
}

// O(n) - Recursive call stack
int factorial(int n) {
    if(n <= 1) return 1;
    return n * factorial(n - 1);  // n function calls on stack
}
```

---

## 21. Common Problem Patterns
*Frequently occurring algorithmic patterns*

### Frequency Counting
```cpp
// Count character frequency
void count_frequency(string s) {
    unordered_map<char, int> freq;
    for(char c : s) {
        freq[c]++;
    }
    
    for(auto [ch, count] : freq) {
        cout << ch << ": " << count << "\n";
    }
}
```

### Prefix/Suffix Processing
```cpp
// Find equilibrium index (sum of left = sum of right)
int find_equilibrium(vector<int>& arr) {
    int total_sum = 0;
    for(int x : arr) total_sum += x;
    
    int left_sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        int right_sum = total_sum - left_sum - arr[i];
        if(left_sum == right_sum) return i;
        left_sum += arr[i];
    }
    return -1;
}
```

### Matrix Traversal
```cpp
// Spiral matrix traversal
void spiral_print(vector<vector<int>>& matrix) {
    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;
    
    while(top <= bottom && left <= right) {
        // Print top row
        for(int j = left; j <= right; j++) cout << matrix[top][j] << " ";
        top++;
        
        // Print right column
        for(int i = top; i <= bottom; i++) cout << matrix[i][right] << " ";
        right--;
        
        // Print bottom row (if exists)
        if(top <= bottom) {
            for(int j = right; j >= left; j--) cout << matrix[bottom][j] << " ";
            bottom--;
        }
        
        // Print left column (if exists)
        if(left <= right) {
            for(int i = bottom; i >= top; i--) cout << matrix[i][left] << " ";
            left++;
        }
    }
}
```

---

## 22. Fast I/O & Competitive Programming Tips
*Optimizations for contest programming*

### Fast I/O Template
```cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);  // Disconnect C++ streams from C streams
    cin.tie(NULL);                     // Untie cin from cout for faster I/O
    cout.tie(NULL);
    
    // Your code here
    
    return 0;
}
```

### Useful Macros
```cpp
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)
#define per(i, a, b) for(int i = b - 1; i >= a; i--)

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
```

### Debug Utilities
```cpp
#ifdef LOCAL
    #define debug(x) cerr << #x << " = " << x << endl
#else
    #define debug(x)
#endif

void print_vector(vector<int>& v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << (i == v.size() - 1 ? "\n" : " ");
    }
}
```

---

## Final Notes

### When to Use What:
- **Array/Vector**: Random access, dynamic size needed
- **LinkedList**: Frequent insertions/deletions at arbitrary positions
- **Stack**: LIFO operations, expression evaluation, backtracking
- **Queue**: FIFO operations, BFS, level order processing
- **Set/Map**: Fast lookup, eliminate duplicates, maintain sorted order
- **Heap**: Priority-based processing, finding min/max efficiently
- **Graph**: Modeling relationships, pathfinding, connectivity problems

### Complexity Goals:
- Try to achieve O(n log n) or better for large inputs
- O(n²) is acceptable for n ≤ 10³
- O(2^n) only works for n ≤ 20
- Always consider both time and space complexity

### Common Mistakes to Avoid:
- Integer overflow (use long long when needed)
- Array bounds checking
- Uninitialized variables
- Memory leaks with dynamic allocation
- Wrong base cases in recursion

---

## 23. Union Find (Disjoint Set Union)
*Efficiently track connected components and cycle detection*

### Basic Implementation
```cpp
class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;  // Initially each node is its own parent
        }
    }
    
    // Find with path compression - O(α(n)) ≈ O(1)
    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
    
    // Union by rank - O(α(n)) ≈ O(1)
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        
        if(px == py) return;  // Already in same component
        
        if(rank[px] < rank[py]) {
            parent[px] = py;
        } else if(rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }
    
    bool same_component(int x, int y) {
        return find(x) == find(y);
    }
};
```

### Applications
```cpp
// Cycle detection in undirected graph
bool has_cycle_dsu(vector<pair<int, int>>& edges, int n) {
    DSU dsu(n);
    for(auto [u, v] : edges) {
        if(dsu.same_component(u, v)) return true;  // Cycle found
        dsu.unite(u, v);
    }
    return false;
}

// Count connected components
int count_components_dsu(vector<pair<int, int>>& edges, int n) {
    DSU dsu(n);
    for(auto [u, v] : edges) {
        dsu.unite(u, v);
    }
    
    set<int> components;
    for(int i = 0; i < n; i++) {
        components.insert(dsu.find(i));
    }
    return components.size();
}
```

---

## 24. Bit Manipulation
*Working with individual bits for optimization*

### Basic Operations
```cpp
// Check if bit at position i is set
bool is_set(int n, int i) {
    return (n & (1 << i)) != 0;
}

// Set bit at position i
int set_bit(int n, int i) {
    return n | (1 << i);
}

// Clear bit at position i
int clear_bit(int n, int i) {
    return n & (~(1 << i));
}

// Toggle bit at position i
int toggle_bit(int n, int i) {
    return n ^ (1 << i);
}

// Count set bits (popcount)
int count_set_bits(int n) {
    return __builtin_popcount(n);
}

// Check if number is power of 2
bool is_power_of_2(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```

### Useful Bit Tricks
```cpp
// Get rightmost set bit
int rightmost_set_bit(int n) {
    return n & (-n);
}

// Turn off rightmost set bit
int turn_off_rightmost(int n) {
    return n & (n - 1);
}

// Swap two numbers without temp variable
void swap_bits(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

// Find single number in array where all others appear twice
int find_single(vector<int>& arr) {
    int result = 0;
    for(int x : arr) {
        result ^= x;  // XOR cancels out duplicates
    }
    return result;
}
```

---

## 25. Mathematical Algorithms
*Common mathematical computations*

### GCD and LCM
```cpp
// Greatest Common Divisor - O(log min(a,b))
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

// Using built-in
int gcd_builtin(int a, int b) {
    return __gcd(a, b);
}

// Least Common Multiple
long long lcm(int a, int b) {
    return (1LL * a * b) / gcd(a, b);
}
```

### Prime Numbers
```cpp
// Check if number is prime - O(√n)
bool is_prime(int n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    
    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Sieve of Eratosthenes - Find all primes up to n
vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    for(int i = 2; i * i <= n; i++) {
        if(is_prime[i]) {
            for(int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}
```

### Modular Arithmetic
```cpp
const int MOD = 1e9 + 7;

// Modular addition
long long add_mod(long long a, long long b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

// Modular multiplication
long long mul_mod(long long a, long long b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

// Modular exponentiation - O(log b)
long long power_mod(long long a, long long b) {
    long long result = 1;
    a %= MOD;
    while(b > 0) {
        if(b & 1) result = mul_mod(result, a);
        a = mul_mod(a, a);
        b >>= 1;
    }
    return result;
}
```

---

## 26. Backtracking
*Explore all possible solutions systematically*

### N-Queens Problem
```cpp
bool is_safe(vector<string>& board, int row, int col, int n) {
    // Check column
    for(int i = 0; i < row; i++) {
        if(board[i][col] == 'Q') return false;
    }
    
    // Check upper left diagonal
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 'Q') return false;
    }
    
    // Check upper right diagonal
    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 'Q') return false;
    }
    
    return true;
}

void solve_n_queens(vector<string>& board, int row, int n, vector<vector<string>>& solutions) {
    if(row == n) {
        solutions.push_back(board);
        return;
    }
    
    for(int col = 0; col < n; col++) {
        if(is_safe(board, row, col, n)) {
            board[row][col] = 'Q';
            solve_n_queens(board, row + 1, n, solutions);
            board[row][col] = '.';  // Backtrack
        }
    }
}
```

### Generate All Subsets
```cpp
void generate_subsets(vector<int>& arr, int idx, vector<int>& current, vector<vector<int>>& result) {
    if(idx == arr.size()) {
        result.push_back(current);
        return;
    }
    
    // Don't include current element
    generate_subsets(arr, idx + 1, current, result);
    
    // Include current element
    current.push_back(arr[idx]);
    generate_subsets(arr, idx + 1, current, result);
    current.pop_back();  // Backtrack
}
```

---

## 27. Greedy Algorithms
*Make locally optimal choices*

### Activity Selection
```cpp
// Select maximum number of non-overlapping activities
int activity_selection(vector<pair<int, int>>& activities) {
    sort(activities.begin(), activities.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;  // Sort by end time
    });
    
    int count = 1;
    int last_end = activities[0].second;
    
    for(int i = 1; i < activities.size(); i++) {
        if(activities[i].first >= last_end) {
            count++;
            last_end = activities[i].second;
        }
    }
    return count;
}
```

### Fractional Knapsack
```cpp
struct Item {
    int value, weight;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;  // Sort by value/weight ratio
}

double fractional_knapsack(vector<Item>& items, int capacity) {
    for(auto& item : items) {
        item.ratio = (double)item.value / item.weight;
    }
    sort(items.begin(), items.end(), compare);
    
    double total_value = 0;
    for(auto& item : items) {
        if(capacity >= item.weight) {
            capacity -= item.weight;
            total_value += item.value;
        } else {
            total_value += item.ratio * capacity;
            break;
        }
    }
    return total_value;
}
```

---

## 28. Contest Strategy & Tips
*Winning approaches for competitive programming*

### Time Management
```cpp
// Quick problem difficulty estimation:
// Easy (5-10 min): Implementation, basic math, simple simulation
// Medium (15-30 min): DP, graphs, data structures
// Hard (45+ min): Advanced algorithms, complex implementation

// Contest strategy:
// 1. Read all problems first (5-10 min)
// 2. Solve in order of difficulty, not problem order
// 3. If stuck for 20+ min, move to next problem
// 4. Always submit brute force if you have partial solution
```

### Input/Output Patterns
```cpp
// Multiple test cases
int t; cin >> t;
while(t--) {
    // Solve each test case
}

// Array input
int n; cin >> n;
vector<int> arr(n);
for(int i = 0; i < n; i++) {
    cin >> arr[i];
}

// 2D array/matrix input
int n, m; cin >> n >> m;
vector<vector<int>> grid(n, vector<int>(m));
for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        cin >> grid[i][j];
    }
}

// String processing
string s; cin >> s;
// or for line with spaces:
getline(cin, s);
```

### Debugging Tips
```cpp
// Assert for debugging (only works in debug mode)
assert(condition);  // Program stops if condition is false

// Print debugging info
#ifdef LOCAL
    for(int x : arr) cerr << x << " ";
    cerr << endl;
#endif

// Check array bounds
if(i < 0 || i >= n) {
    cout << "Index out of bounds!" << endl;
    return;
}
```

---

## 29. Problem Categories Quick Reference
*Common problem types and their approaches*

### Array Problems
- **Two Sum/Pair Sum**: Hash map or two pointers
- **Subarray Problems**: Prefix sum, sliding window, Kadane's
- **Sorting/Searching**: Built-in sort, binary search
- **Rotation**: Reverse technique or cyclic approach

### String Problems  
- **Palindrome**: Two pointers, expand around center
- **Anagram**: Frequency counting, sorting
- **Pattern Matching**: KMP, built-in find()
- **Subsequence**: DP, greedy approach

### Tree Problems
- **Traversal**: DFS (recursive), BFS (queue)
- **Height/Depth**: Recursive with max()
- **Path Sum**: DFS with target tracking
- **LCA**: Binary lifting, parent tracking

### Graph Problems
- **Shortest Path**: BFS (unweighted), Dijkstra (weighted)
- **Connected Components**: DFS/BFS, Union Find
- **Cycle Detection**: DFS (back edges), Union Find
- **Topological Sort**: DFS, Kahn's algorithm

### DP Problems
- **Linear DP**: Fibonacci-like, LIS, LCS
- **2D DP**: Grid paths, knapsack variants  
- **Tree DP**: Max path sum, diameter
- **State Space**: Bitmask DP, digit DP

---

## Final Exam/Contest Checklist ✓

### Before Contest:
- [ ] Template ready with fast I/O
- [ ] Know STL containers and their time complexities
- [ ] Practice common algorithms (sorting, searching, graph)
- [ ] Understand when to use which data structure

### During Contest:
- [ ] Read all problems first
- [ ] Start with easiest problems
- [ ] Handle edge cases (empty input, single element)
- [ ] Use long long for large numbers
- [ ] Test with sample inputs
- [ ] Submit partial solutions if stuck

### Common Edge Cases:
- Empty arrays/strings (n = 0)
- Single element (n = 1)  
- All elements same
- Negative numbers
- Integer overflow
- Graph disconnected/has cycles