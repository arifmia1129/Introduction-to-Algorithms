#include<bits/stdc++.h>
using namespace std;

int main () {
    int n, e;

    cin >> n >> e;

    vector<int> adjList[n];

    

    while(e--) {
        int a, b;

        cin >> a >> b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    int q;

    cin >> q;

    while(q--) {
        int x;

        cin >> x;

        vector<int> v = adjList[x];

        if(v.empty()) {
            cout << -1 << endl;
        }else {
            sort(v.begin(), v.end(), greater<int>());

            for(int i : v){
                cout << i << " ";
            }
            cout << endl;
            }
    }

    return 0;
}