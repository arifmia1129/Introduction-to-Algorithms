#include<bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
int level[105][105];

vector<pair<int, int>> d = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

int n, m;

bool isValid(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m)
     return false;
    
    return true;
}

void bfs(int si, int sj) {
    queue<pair<int, int>> q;

    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while(!q.empty()) {
        pair<int, int> par = q.front();

        q.pop();

        int par_i = par.first;
        int par_j = par.second;

        // cout << par_i << " " << par_j << endl;

        for(int i = 0; i < 4; i++) {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            if(isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.'){
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
                q.push({ci, cj});
            }
                
        }
    }
}

int main () {
    cin >> n >> m;

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));

    int si, sj, di, dj; cin >> si >> sj >> di >> dj;

    bfs(si, sj);

    cout << level[di][dj];

    return 0;
}