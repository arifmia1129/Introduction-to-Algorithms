#include<bits/stdc++.h>
using namespace std;

long long int dpIdx[10000005];
bool dp[10000005];

bool makeIt(long long int crt, long long int n) {
    if(crt == n) return true;
    if(crt > n) return false;

    if(dpIdx[crt] != -1)
        return dp[crt];

    dp[crt] = makeIt(crt + 3, n) || makeIt(crt * 2, n);
    dpIdx[crt] = 1;

    return dp[crt];
}

int main () {
    int t; cin >> t;

    while(t--) {
        long long int n; cin >> n;

        for(int i = 0; i < n; i++) {
            dpIdx[i] = -1;
            dp[i] = false;
        }

        if(makeIt(1, n))
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }

    return 0;
}