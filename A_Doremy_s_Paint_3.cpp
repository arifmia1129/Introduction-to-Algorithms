#include<bits/stdc++.h>
using namespace std;

int main () {
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;

        int a[n];
        map<int, int> mp;

        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }

        if(mp.size() > 2) cout << "No\n";
        else if(mp.size() == 2) {
            vector<int> v;

            for(auto e : mp) v.push_back(e.second);

            if(abs(v[0] - v[1]) > 1) cout << "No\n";
            else cout << "Yes\n";

        }else cout << "Yes\n";
    }

    return 0;
}