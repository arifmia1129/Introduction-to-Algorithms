#include<bits/stdc++.h>
using namespace std;

int n, m;

char grid[105][105];
bool vis[105][105];

vector<pair<int, int>> direction = {{ -1, 0 }, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m)
        return false;

    return true;
}

void dfs(int si, int sj) {
    // cout << si << " " << sj << endl;
    vis[si][sj] = true;

    if(grid[si][sj] == 'E')
        return;

    for(int i = 0; i < 4; i++) {
        int ci = si + direction[i].first;
        int cj = sj + direction[i].second;

        if(isValid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'E')) {
            dfs(ci, cj);
        }
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
           if(!vis[i][j] && grid[i][j] == '.') {
                cnt++;
                dfs(i, j);
           }
               
        }
    }

    cout << cnt << endl;;

    return 0;
}