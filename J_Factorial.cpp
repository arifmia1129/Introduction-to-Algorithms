#include<bits/stdc++.h>
using namespace std;


long long int fac(long long int n) {
    if(n == 1) return 1;

    return n * fac(n - 1);
}

int main () {
    long long int n; cin >> n;

    cout << fac(n) << endl;

    return 0;
}