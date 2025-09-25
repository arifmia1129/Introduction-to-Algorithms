# Question 14: BFS on 2D Grid - Shortest Path

## Problem Statement
You are given a 2D grid with obstacles. Find the minimum number of steps to reach from source (0,0) to destination (n-1,m-1). You can move in 4 directions (up, down, left, right). '.' represents free cell and '#' represents obstacle.

## Input Format
- First line contains n and m (dimensions)
- Next n lines contain the grid
- Source is always (0,0) and destination is (n-1,m-1)

## Constraints
- 1 ≤ n, m ≤ 100
- Grid contains only '.' and '#'
- Source and destination are always '.'

## Output Format
Print minimum steps to reach destination. If not possible, print -1

## Sample Input 0
```
4 4
....
.##.
....
...#
```

## Sample Output 0
```
6
```

## Sample Input 1
```
3 3
...
###
...
```

## Sample Output 1
```
-1
```

## Solution

```cpp
#include<bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool valid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs_2d(vector<string>& grid, int n, int m) {
    if(grid[0][0] == '#' || grid[n-1][m-1] == '#') return -1;
    
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> dis(n, vector<int>(m, -1));
    
    queue<pair<int, int>> q;
    
    q.push({0, 0});
    vis[0][0] = true;
    dis[0][0] = 0;
    
    while(!q.empty()) {
        pair<int, int> par = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int ci = par.first + dx[i];
            int cj = par.second + dy[i];
            
            if(valid(ci, cj, n, m) && !vis[ci][cj] && grid[ci][cj] == '.') {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[par.first][par.second] + 1;
            }
        }
    }
    
    return dis[n-1][m-1];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    
    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    cout << bfs_2d(grid, n, m) << "\n";
    
    return 0;
}
```

## Time Complexity: O(n × m)
## Space Complexity: O(n × m)

## Approach
We use BFS (Breadth-First Search) to find the shortest path in an unweighted grid. BFS guarantees that the first time we reach the destination, it's via the shortest path. We maintain visited array and distance array to track the minimum steps to each cell.