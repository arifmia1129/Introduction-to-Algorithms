#include<bits/stdc++.h>
using namespace std;

int n, m;
char grid[105][105];
bool vis[105][105];
int level[105][105];

vector<pair<int,int>> directions = {{2, -1}, {1, -2}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};

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

            if(isValid(ch_i, ch_j) && !vis[ch_i][ch_j]) {
                level[ch_i][ch_j] = level[par_i][par_j] + 1;
                vis[ch_i][ch_j] = true;
                q.push({ch_i, ch_j});
            }
        }
    }
}


int main () {
    int t; cin >> t;

    while(t--) {
    cin >> n >> m;

    int si, sj, di, dj; cin >> si >> sj >> di >> dj;

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));

    bfs(si, sj);

    cout << level[di][dj] << endl;
    }
    
    return 0;
}