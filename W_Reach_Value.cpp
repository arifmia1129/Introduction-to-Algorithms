#include<bits/stdc++.h>
using namespace std;


bool canReach(int crt, int n) {
    if(crt == n) return true;
    if(crt > n) return false;

    return canReach(crt * 10, n) || canReach(crt * 20, n);
}

int main () {
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;

        if(canReach(1, n))
            cout << "YES\n";
        else 
            cout << "NO\n";
    }

    return 0;
}