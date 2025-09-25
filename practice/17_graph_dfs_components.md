# Question 17: Count Connected Components using DFS

## Problem Statement
Given an undirected graph, find the number of connected components.

## Input Format
- First line contains n (number of nodes) and m (number of edges)
- Next m lines contain edges (u, v)
- Nodes are numbered from 0 to n-1

## Constraints
- 1 ≤ n ≤ 10³
- 0 ≤ m ≤ n(n-1)/2
- 0 ≤ u, v < n

## Output Format
Print the number of connected components

## Sample Input 0
```
6 4
0 1
1 2
3 4
4 5
```

## Sample Output 0
```
2
```

## Sample Input 1
```
5 0
```

## Sample Output 1
```
5
```

## Solution

```cpp
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

void dfs(int src) {
    vis[src] = true;
    
    for(int child : adj[src]) {
        if(!vis[child]) {
            dfs(child);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    
    adj.resize(n);
    vis.resize(n, false);
    
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int components = 0;
    
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i);
            components++;
        }
    }
    
    cout << components << "\n";
    
    return 0;
}
```

## Time Complexity: O(V + E)
## Space Complexity: O(V + E)

## Approach
We use DFS to traverse the graph. For each unvisited node, we start a new DFS which covers one complete connected component. The number of times we start DFS equals the number of connected components.