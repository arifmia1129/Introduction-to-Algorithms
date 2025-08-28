#include<bits/stdc++.h>
using namespace std;

int n, m;

char grid[1005][10005];
bool vis[1005][1005];

vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m) 
        return false;
    
    return true;
}

void dfs(int si, int sj) {
    vis[si][sj] = true;

    for(auto d : directions) {
        int ci = si + d.first;
        int cj = sj + d.second;

        if(isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
            dfs(ci, cj);
    }
}


int main () {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    int cnt = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && grid[i][j] == '.'){
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    
    return 0;
}