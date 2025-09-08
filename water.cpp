#include<bits/stdc++.h>
using namespace std;

int main () {
    int t; cin >> t;

    
    while(t--) {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        int n; cin >> n;

        for(int i = 0; i < n; i++) {
            int v; cin >> v;
            pq.push({v, i});
        }

        ans.push_back(pq.top().second);

        pq.pop();

        ans.push_back(pq.top().second);

        sort(ans.begin(), ans.end());
        
        for(int a : ans)
            cout << a << " ";
        
        cout << endl;
    }

    return 0;
}