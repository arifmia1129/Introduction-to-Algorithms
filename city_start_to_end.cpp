#include<bits/stdc++.h>
using namespace std;

int n, m;

char grid[1005][1005];
bool vis[1005][1005];

vector<pair<int, int>> direction = {{ -1, 0 }, {1, 0}, {0, -1}, {0, 1}};

vector<int> rooms;

int roomsCnt = 0;

bool isValid(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m)
        return false;

    return true;
}

void dfs(int si, int sj) {
    // cout << si << " " << sj << endl;
    vis[si][sj] = true;
    roomsCnt++;

    for(int i = 0; i < 4; i++) {
        int ci = si + direction[i].first;
        int cj = sj + direction[i].second;

        if(isValid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.')) {
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

    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
           if(!vis[i][j] && grid[i][j] == '.') {
                dfs(i, j);
                if(roomsCnt > 0) {
                    rooms.push_back(roomsCnt);
                    roomsCnt = 0;
                }
           }
          
        }
        
    }

    if(rooms.empty()) {
        cout << 0 << endl;
    }else {

        sort(rooms.begin(), rooms.end());


        for(int x : rooms)
            cout << x << " ";
    }


    return 0;
}