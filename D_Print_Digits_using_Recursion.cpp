#include<bits/stdc++.h>
using namespace std;

void rec(string s, int idx) {
    if(idx >= s.size()) return;

    cout << s[idx] << ' ';

    rec(s, idx + 1);
}

int main () {
    int t; cin >> t;

    while(t--) {
        string s; cin >> s;
        rec(s, 0);

        cout << endl;
    }
    
    return 0;
}