#include<bits/stdc++.h>
using namespace std;

int fac(int n) {
    if(n == 1) return 1;

    int mul = fac(n - 1);

    return mul * n;
}

int main () {
    int res = fac(5);

    cout << res << endl;

    return 0;
}