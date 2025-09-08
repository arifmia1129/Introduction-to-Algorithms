#include<bits/stdc++.h>
using namespace std;

int n;
char grid[35][35];
bool vis[35][35];
int level[35][35];

vector<pair<int, int> > directions;

bool isValid(int i, int j) {
    return i < n && i >= 0 && j < n && j >= 0;
}

void bfs(int si, int sj) {
    queue<pair<int,int> > q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while(!q.empty()) {
        auto parent = q.front();
        q.pop();

        for(auto d : directions) {
            int ci = parent.first + d.first;
            int cj = parent.second + d.second;

            if(isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != 'T'){
               vis[ci][cj] = true;
               level[ci][cj] = level[parent.first][parent.second] + 1;
               q.push({ci, cj});
            }
        }
    }
}

int main () {
    directions.push_back({1, 0});
    directions.push_back({-1, 0});
    directions.push_back({0, -1});
    directions.push_back({0, 1});
    while(cin >> n) {
        int si, sj, di, dj;

        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));


        for(int i = 0; i < n; i++) {
            for(int  j = 0; j < n; j++) {
                cin >> grid[i][j];

                if(grid[i][j] == 'S') {
                    si = i;
                    sj = j;
                }
                if(grid[i][j] == 'E') {
                    di = i;
                    dj = j;
                }

                
            }
        }

        bfs(si, sj);

        cout << level[di][dj] << endl;

    }
    
    return 0;
}