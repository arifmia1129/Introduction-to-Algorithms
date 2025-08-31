    #include<bits/stdc++.h>
    using namespace std;

    int total = 0;
    vector<int> components;
    int n, m;
    char grid[1005][1005];
    bool vis[1005][1005];

    vector<pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


    bool isValid(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    void dfs(int si, int sj) {
        vis[si][sj] = true;
        total++;

        for(auto d : directions) {
            int ci = si + d.first;
            int cj = sj + d.second;

            if(isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.') {
                dfs(ci, cj);
            }
        }
    }


    int main () {
        cin >> n >> m;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) 
                cin >> grid[i][j];
        }


        memset(vis, false, sizeof(vis));


        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                total = 0;
                if(!vis[i][j] && grid[i][j] == '.') {
                    dfs(i, j);
                    components.push_back(total);
                }
            }
        }

        sort(components.begin(), components.end());

        if(components.empty()) 
            cout << -1 << endl;
        else 
            cout << components.front() << endl;
        
        return 0;
    }