#include<bits/stdc++.h>
using namespace std;

int main () {
    int t; cin >> t;

    while(t--) {
        int n, m; cin >> n >> m;

        string s; cin >> s;
        
        int freAr[7] = {0};

        for(char ch : s) 
            freAr[ch - 'A']++;

        int cnt = 0;

        for(int v : freAr) 
            if(v < m) cnt += m - v;

        cout << cnt << endl;
    }

    return 0;
}