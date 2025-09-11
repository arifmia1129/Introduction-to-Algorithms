#include<bits/stdc++.h>
using namespace std;


bool canReach(long long n) {
    if(n == 1) return true;
    if(n == 0) return false;

    bool l = false, r = false;

    if(n % 10 == 0) {
        l = canReach(n / 10);
    }
    if(n % 20 == 0) {
        r = canReach(n / 20);
    }

    return l || r;
}

int main () {
    int t; cin >> t;

    while(t--) {
        long long n; cin >> n;

        if(canReach(n))
            cout << "YES\n";
        else 
            cout << "NO\n";
    }

    return 0;
}