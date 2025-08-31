#include<bits/stdc++.h>
using namespace std;

int n, m;
char grid[1005][1005];
bool vis[1005][1005];
int level[1005][1005];
pair<int, int> parent[1005][1005];

vector<pair<int,int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void bfs(int si, int sj) {
    queue<pair<int,int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;
    


    while(!q.empty()) {
        auto par = q.front();

        q.pop();

        int par_i = par.first;
        int par_j = par.second;

        for(auto d : directions) {
            int ch_i = par_i + d.first;
            int ch_j = par_j + d.second;

            if(isValid(ch_i, ch_j) && !vis[ch_i][ch_j] && (grid[ch_i][ch_j] == '.' || grid[ch_i][ch_j] == 'D')) {
                vis[ch_i][ch_j] = true;
                q.push({ch_i, ch_j});
                level[ch_i][ch_j] = level[par_i][par_j] + 1;
                parent[ch_i][ch_j] = {par_i, par_j};
            }
        }
    }
}


int main () {
    cin >> n >> m;

    int si, sj, di, dj;


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];

            if(grid[i][j] == 'R') {
                si = i;
                sj = j;
            }

            if(grid[i][j] == 'D'){
                di = i;
                dj = j;
            }
        }
            
    }


    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));

    for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        parent[i][j] = {-1, -1};
    }
}


    bfs(si, sj);

    if(vis[di][dj]){
        pair<int, int> node = {di, dj};

        while(node.first != -1) {
           if (!(node.first == si && node.second == sj) && 
            !(node.first == di && node.second == dj)) {
            grid[node.first][node.second] = 'X';
        }

            node = parent[node.first][node.second];
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                cout << grid[i][j];
            }

            cout << endl;   
    }
    }
    else 
        {
            for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                cout << grid[i][j];
            }

            cout << endl;   
    }
        }


    
    
    return 0;
}