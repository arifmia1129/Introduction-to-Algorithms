#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main () {
    int t; cin >> t;

    while(t--) {
        ll x, y; cin >> x >> y;

        ll leftVal = min(x, y) - 1;
        ll rightVal = max(x, y);


        ll leftSum = (leftVal * (leftVal + 1)) / 2;
        ll rightSum = (rightVal * (rightVal + 1)) / 2;

        cout << rightSum - leftSum << endl;
    }

    return 0;
}