# Question 18: Dijkstra's Shortest Path Algorithm

## Problem Statement
Given a weighted directed graph, find the shortest distance from source node 0 to all other nodes.

## Input Format
- First line contains n (nodes) and m (edges)
- Next m lines contain u, v, w (edge from u to v with weight w)
- Nodes are numbered from 0 to n-1

## Constraints
- 1 ≤ n ≤ 10³
- 0 ≤ m ≤ n(n-1)
- 1 ≤ w ≤ 10⁴
- 0 ≤ u, v < n

## Output Format
Print shortest distance from node 0 to each node (0 to n-1). If unreachable, print -1

## Sample Input 0
```
4 5
0 1 2
0 2 4
1 2 1
1 3 7
2 3 3
```

## Sample Output 0
```
0 2 3 6
```

## Solution

```cpp
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    
    vector<vector<pair<int, int>>> adj(n);
    
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        
        adj[u].push_back({v, w});
    }
    
    vector<int> dis(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dis[0] = 0;
    pq.push({0, 0});
    
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
    
    for(int i = 0; i < n; i++) {
        if(dis[i] == INF) {
            cout << -1;
        } else {
            cout << dis[i];
        }
        
        if(i < n - 1) cout << " ";
    }
    cout << "\n";
    
    return 0;
}
```

## Time Complexity: O((V + E) log V)
## Space Complexity: O(V + E)

## Approach
Dijkstra's algorithm finds shortest paths from a source to all other vertices. We use a min-priority queue to always process the vertex with minimum distance. For each vertex, we relax all its neighbors if we find a shorter path.