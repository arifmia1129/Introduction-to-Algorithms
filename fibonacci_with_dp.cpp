#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll dp[1005];

ll fib(int n) {
    if(n < 2) return n;

    if(dp[n] != -1) return dp[n];

    dp[n] = fib(n - 1) + fib(n - 2);

    return dp[n];
}

int main () {
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));


    cout << fib(n) << endl;


    return 0;
}